#include<stdio.h>
#define N 6

//関数はvoid(戻り値無し,return無し)
void add(int *p, int *q, int *r){
  for (int i = 0; i < N; i++) r[i] =  p[i] + q[i];
}

//関数はintを戻す(関数内return有り)
int *sub(int *p, int *q){
  //引算値をwk[N]に代入
  static int wk[N];
  for (int i = 0;i < N; i++) wk[i] = p[i] - q[i];
  return wk;
}

int main(void){
  printf("/**** P3-4(関数の引数が配列) ****");
  int a[N] = {1,2,3,4,5,6};
  int b[N] = {19, 18, 17, 16, 15, 14};
  int w[N] ;

  add(a, b, w);
  printf("\n a + b = ");
  for (int i = 0; i < N; i++) printf("w[%d] = %d ", i, w[i]);

  int *v = sub(a, b);
  printf("\n a - b = ");
  for(int i = 0;i < N; i++) printf("v[%d] = %d ", i, v[i]);
  printf("\n*/\n");

}
