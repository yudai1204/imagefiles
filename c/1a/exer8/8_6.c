#include <stdlib.h>
#include "Kiso2A.h"

int main(void)
{
  //kを読み込む
  int k;
  scanf("%d", &k);

  //TODO ここを編集
  //ヒント：ヒープの親子関係（indexが奇数なら左の子、偶数なら右の子、親は(index-1)/2)
  int route[21];
  for (int i = 0; i <21; i++){
    route[i] = 0;
  }
  route[0] = k;
  for (int i = 1; k > 0; i++){
    route[i] = k = (k-1)/2;
  }
  for (int i=20;i>=0;i--){
    if(route[i] == 0){
      continue;
    }
    if(route[i]%2 == 0){
      printf("R ");
    }else{
      printf("L ");
    }
  }
  printf("\n");
  return 0; 
}