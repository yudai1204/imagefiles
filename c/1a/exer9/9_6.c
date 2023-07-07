#include "Kiso2A.h"

//双方向連結リストだと便利
typedef struct Node
{
  int key ;
  int next; //ポインタではなくidxで持つ idx=-1なら非連結
  int prev; //ポインタではなくidxで持つ idx=-1なら非連結
} Node;



int main()
{
  int N, Q;
  scanf("%d %d", &N, &Q);

  Node trains[100000]; //十分長くとる

  //N個の電車を初期化
  for ( int i=0; i < N; ++i){
    trains[i].key = i;
    trains[i].prev = trains[i].next = -1;
  }

  for (int i=0; i < Q; ++i)
  {
    int q;
    scanf("%d", &q);

    if (q == 1) //連結
    {
      //上記のデータ構造を使うと連結が以下のように書ける
      int x, y;
      scanf("%d %d", &x, &y);
      x = x-1; 
      y = y-1; //indexが1から始まるのでその補正
      trains[x].next = y;
      trains[y].prev = x;
    }
    else if(q ==2) //切り離し
    {
      int x, y;
      scanf("%d %d", &x, &y);
      //TODO ここを編集（切り離す）
      x = x-1; 
      y = y-1; //indexが1から始まるのでその補正
      trains[x].next = -1;
      trains[y].prev = -1;
    }
    else if(q ==3)//print
    {
      // TODO ここも編集
      // trains[x]につながったノードを数える
      // trains[x]に連結した要素を先頭からprint
      int x;
      int cnt = 0;
      scanf("%d",&x);
      x = x-1;
      int y = x;//保存用
      //ラストまで数える
      for(;trains[x].next != -1;cnt++){
        x = trains[x].next;
      }
      x = y;
      //先頭に行く
      for(;trains[x].prev != -1;cnt++){
        x = trains[x].prev;
      }
      printf("%d ",cnt+1);
      while(x != -1){
        //printf("key:%dnext:%dprev%d ",trains[x].key,trains[x].next,trains[x].prev);
        printf("%d ",trains[x].key+1);
        x = trains[x].next;
      }
      printf("\n");
    }
  }
  return 0;
}



