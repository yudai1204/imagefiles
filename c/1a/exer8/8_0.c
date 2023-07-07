#include "Kiso2A.h"


// binary search tree 
int main(void)
{
  int N;
  scanf("%d", &N);

  //TODO ここを編集．N個の整数を読み込み逆順に出力する．
  int* in = (int*)malloc(N*sizeof(int));
  for(int i=0; i<N; i++){
    scanf("%d", &in[i]);
  }
  for(int i=N-1; i>=0; i--){
    printf("%d ", in[i]);
  }
  printf("\n");
  return 1;
}
