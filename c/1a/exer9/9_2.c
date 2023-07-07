#include "Kiso2A.h"

//このテンプレートでは配列で実装します 
// (テンプレートを無視して連結リストで実装してもOK!)
// 
// int queue[] --> queueの中身を入れる配列
// int top  --> 先頭要素のindex、   (a[top ]から取り出す 
// int tail --> 末尾要素の次のindex (a[tail]に入れる
// top == tail なら空
//  
// queue = [e, e, e, 1, 2, 3, 5, e, e, e] という状態なら
// top = 3, tail = 7, (eは要素なしを意味する)

void print_queue(int queue[], int top, int tail)
{
  for (int i = top; i < tail; ++i)
    printf("%d ", queue[i]);
  printf("\n");
}

//queueの後ろにvalを入れる（enqueueする）
void enqueue(int queue[], int *top, int *tail, int val)
{
  //TODO ここを編集
  //queue[*tail]にvalを入れてtailをひとつ進めればOK
  queue[*tail] = val;
  *tail+=1;
}

//queueの先頭から値を取り出す（dequeueする）
int dequeue(int queue[], int *top, int *tail)
{
  //TODO ここを編集
  //queue[*top]を返す。同時に*topをひとつ動かして次の要素を指すようにする。
  int ret = *top;
  *top+=1;
  return queue[ret];
}


int main()
{
  int N;
  scanf("%d", &N);

  int queue[1000]; //絶対にはみ出さないように、十分長い配列を用意
  int top = 0,  tail = 0;

  for (int i = 0; i < N; ++i)
  {
    int q, x;
    scanf("%d %d", &q, &x);
    if (q == 1) 
      enqueue(queue, &top, &tail, x);
    if (q == 2)
    {
      if (top == tail) printf("e\n");
      else printf("%d\n", dequeue(queue, &top, &tail));
    }
    if (q == 3)
      print_queue(queue, top, tail);
  }
  return 0;
}
