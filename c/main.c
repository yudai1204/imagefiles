#include <windows.h>
#include <scrnsave.h>
#include <gl/gl.h>
#include <stdio.h>
#include <process.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void EnableOpenGL(void); // prototype宣言
void DisableOpenGL(HWND); // prototype宣言
HDC hDC;
HGLRC hRC;
int speed; // ボールのスピード
char next[3]; // 改行コードを読み飛ばすための変数
int wx, wy; // displayの横と縦のpixel数格納用変数
int finish = 0; /* 生成したスレッドを終了させるかどうかを最初のスレッド
		   から通知するための変数。0なら終了しない、1なら終了 */
int ballArray[10] // ボールの座標を格納する配列
          = {
              10, 10, // ボール1の座標
              10, 10, // ボール2の座標
              10, 10, // ボール3の座標
              10, 10, // ボール4の座標
              10, 10  // ボール5の座標
            };
int ballDirectionArray[10] = {
              0, 0, // ボール1の方向
              0, 0, // ボール2の方向
              0, 0, // ボール3の方向
              0, 0, // ボール4の方向
              0, 0  // ボール5の方向
            };
float ballColorArray[15] = {
              0.0, 0.0, 1.0, // ボール1の色
              0.0, 0.0, 1.0, // ボール2の色
              0.0, 0.0, 1.0, // ボール3の色
              0.0, 0.0, 1.0, // ボール4の色
              0.0, 0.0, 1.0  // ボール5の色
            };

void display (char * ssd) 
{
  // static修飾子がついているのは、次のdisplay関数呼び出し時に前の値を使うため。
  static int i=0; // URDL100文字格納配列のインデックス
  char direction; // 正方形が動く方向（URDLのどれか）を格納するための変数

  i=i % 100; // URDL100文字格納配列のindexを0から99の範囲で動かすため
  direction = ssd[i]; // i番目の文字をdirectionに代入
  i++; // 次のdisplay関数呼び出し時のためにiの値を増やす
  // char型の数字をint型に直す
  switch(direction){
    case '0':
      ballColorArray[0] = (float)(rand()) / RAND_MAX;
      ballColorArray[1] = (float)(rand()) / RAND_MAX;
      ballColorArray[2] = (float)(rand()) / RAND_MAX;
      break;
    case '1':
      ballColorArray[3] = (float)(rand()) / RAND_MAX;
      ballColorArray[4] = (float)(rand()) / RAND_MAX;
      ballColorArray[5] = (float)(rand()) / RAND_MAX;
      break;
    case '2':
      ballColorArray[6] = (float)(rand()) / RAND_MAX;
      ballColorArray[7] = (float)(rand()) / RAND_MAX;
      ballColorArray[8] = (float)(rand()) / RAND_MAX;
      break;
    case '3':
      ballColorArray[9] = (float)(rand()) / RAND_MAX;
      ballColorArray[10] = (float)(rand()) / RAND_MAX;
      ballColorArray[11] = (float)(rand()) / RAND_MAX;
      break;
    case '4':
      ballColorArray[12] = (float)(rand()) / RAND_MAX;
      ballColorArray[13] = (float)(rand()) / RAND_MAX;
      ballColorArray[14] = (float)(rand()) / RAND_MAX;
      break;
    default:
      break;
  }
  glClear(GL_COLOR_BUFFER_BIT); // 画面全体をglClearColorで指定した色で塗る
  // すべてのボールの座標を更新して表示
  for(int i=0; i<5; i++){
    glColor3f(ballColorArray[i*3], ballColorArray[i*3+1], ballColorArray[i*3+2]); // glRectf等で描画するときの色設定
    // ボールの座標を更新
    ballArray[i*2] += ballDirectionArray[i*2];
    ballArray[i*2+1] += ballDirectionArray[i*2+1];
    // ボールが画面の端に来たら反射させる
    if(ballArray[i*2] < -90 || ballArray[i*2] > 90){
      ballDirectionArray[i*2] *= -1;
    }
    if(ballArray[i*2+1] < -55 || ballArray[i*2+1] > 55){
      ballDirectionArray[i*2+1] *= -1;
    }
    glRectf(ballArray[i*2], ballArray[i*2+1], ballArray[i*2]+5, ballArray[i*2+1]+5); // 長方形（ボール） を表示
  }
}
unsigned __stdcall disp (void *arg) {
  char ssd[100];
  FILE *fp=NULL;

  EnableOpenGL(); // OpenGL設定

  /* OpenGL初期設定 */
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0*wx/wy, 50.0*wx/wy, -50.0, 50.0, -50.0, 50.0); // 座標系設定

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  glClearColor(0.1f, 0.2f, 0.3f, 0.0f); // glClearするときの色設定
  glColor3f(0.9, 0.8, 0.7); // glRectf等で描画するときの色設定
  glViewport(0,0,wx,wy);
  /* ここまで */

  /* スクリーンセーバ記述プログラム読み込み */
  fp=fopen ("sample1", "r");
  if (fp==NULL) {
    fprintf (stderr, "failed to open the file \"sample1\"\n");
    exit(0);
  }
  fscanf (fp, "%d", &speed); // 1文字読み込み→速度に代入
  fscanf (fp, "%c", &next[0]); //改行コードを読み飛ばす
  for (int i=0; i<100; i++)
    if (fscanf (fp, "%c", &ssd[i]) == EOF){ // 100文字なかったら終了
      fprintf (stderr, "The length of the input is less than 100.\n");
      exit(0);
    }
  fclose(fp);
  /* ここまで */
  // 最初の方向を乱数で決める
  srand((unsigned int)time(NULL)); // 現在時刻の情報で初期化
  for(int i=0; i<10; i++){
    float direction =  3.1416 * 2 * rand() / RAND_MAX ;
  // 無理やり長さspeedのx,y方向のベクトルを作る
    ballDirectionArray[i*2] = (int)(cos(direction) * speed);
    ballDirectionArray[i*2+1] = (int)(sin(direction) * speed);
  }
  /* 表示関数呼び出しの無限ループ */  
  while(1) {
    Sleep(30); // 0.030秒待つ
    display(ssd); // 描画関数呼び出し
    glFlush(); // 画面描画強制
    SwapBuffers(hDC); // front bufferとback bufferの入れ替え
    if (finish == 1) // finishが1なら描画スレッドを終了させる
      return 0;
  }
}

LRESULT WINAPI ScreenSaverProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
  static HANDLE thread_id1;
  RECT rc;

  switch(msg) {
  case WM_CREATE:
    hDC = GetDC(hWnd); // ウィンドウハンドルhWndからデバイスコンテクストを取得
    GetClientRect(hWnd, &rc); /* hWndのウィンドウの左上と右下の座標を
				 構造体rcに格納する。*/
    wx = rc.right - rc.left; /* GetClientRectで取得した左上、右下の座標を使って
				displayの横のpixel数を計算 */
    wy = rc.bottom - rc.top; /* GetClientRectで取得した左上、右下の座標を使って
				displayの縦のpixel数を計算 */

    thread_id1=(HANDLE)_beginthreadex(NULL, 0, disp, NULL, 0, NULL); // 描画用スレッド生成
    if(thread_id1==0){ // スレッド生成に失敗したらスクリーンセーバを終了
      fprintf(stderr,"pthread_create : %s", strerror(errno));
      exit(0);
    }
    break;
  case WM_ERASEBKGND:
    return TRUE;
  case WM_DESTROY: // マウスやキーボードの入力があるとここに来る
    finish=1; // 描画スレッドを終了させるために1を代入
    WaitForSingleObject(thread_id1, INFINITE); // 描画スレッドの終了を待つ
    CloseHandle(thread_id1); // 生成したスレッドを閉じる
    DisableOpenGL(hWnd);
    PostQuitMessage(0); /* 自分のスレッド（メインスレッド）を終了していいことを
			   自分のメッセージキューに入れる。 */
    return 0;
  default: // 上記以外のメッセージの場合はswitch文を終了。（これは書かなくても同じだが。）
    break;
  }
  return DefScreenSaverProc(hWnd, msg, wParam, lParam); /* 上のswitch文で処理していない
							   メッセージを処理してからreturn。*/
}

/* https://msdn.microsoft.com/ja-jp/library/cc422062.aspx 参照 */
BOOL WINAPI ScreenSaverConfigureDialog(HWND hDlg, UINT msg, WPARAM wParam, LPARAM lParam)
{
  return TRUE;
}

/* https://msdn.microsoft.com/ja-jp/library/cc422061.aspx 参照 */
BOOL WINAPI RegisterDialogClasses(HANDLE hInst)
{
  return TRUE;
}

void EnableOpenGL(void) {
  int format;
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd368826(v=vs.85).aspx
     を参照 */
  PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR), // size of this pfd
    1,                     // version number
    0
    | PFD_DRAW_TO_WINDOW   // support window
    | PFD_SUPPORT_OPENGL   // support OpenGL
    | PFD_DOUBLEBUFFER     /* double buffered 
			      (front bufferとback bufferの2枚使う) */
    ,      
    PFD_TYPE_RGBA,         // RGBA type
    24,                    // 24-bit color depth
    0, 0, 0, 0, 0, 0,      // color bits ignored
    0,                     // no alpha buffer
    0,                     // shift bit ignored
    0,                     // no accumulation buffer
    0, 0, 0, 0,            // accum bits ignored
    32,                    // 32-bit z-buffer
    0,                     // no stencil buffer
    0,                     // no auxiliary buffer
    PFD_MAIN_PLANE,        // main layer
    0,                     // reserved
    0, 0, 0                // layer masks ignored
  };

  /* OpenGL設定 */  
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd318284(v=vs.85).aspx 参照 */
  format = ChoosePixelFormat(hDC, &pfd);
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd369049(v=vs.85).aspx 参照 */
  SetPixelFormat(hDC, format, &pfd);
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd374379(v=vs.85).aspx 参照 */
  hRC = wglCreateContext(hDC);
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd374387(v=vs.85).aspx 参照 */
  wglMakeCurrent(hDC, hRC);
  /* ここまで */
}

void DisableOpenGL(HWND hWnd)
{
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd374387(v=vs.85).aspx 参照 */
  wglMakeCurrent(NULL, NULL);
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd374381(v=vs.85).aspx 参照 */
  wglDeleteContext(hRC);
  /* https://msdn.microsoft.com/en-us/library/windows/desktop/dd162920(v=vs.85).aspx 参照 */
  ReleaseDC(hWnd, hDC);
}
