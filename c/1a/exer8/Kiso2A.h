#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// IO 処理を書いておきます。 
// 使ってもよいですし使わなくてもよいです。

// load the following style input 
// N
// a1 a2 a3 ... aN
// 
// note: ai should be allocated 
void load_ai(int *N, int ai[])
{
  scanf("%d", N);
  for (int i = 0; i < *N; ++i)
  {
    scanf("%d", &(ai[i]));
  }
}



// load the following style input 
// N M
// a1 a2 a3 ... aN
// b1 b2 b3 ... bM
// 
// note: ai and bi should be allocated 
void load_ai_bj(int* N, int* M, int ai[], int bi[])
{
  scanf("%d", N);
  scanf("%d", M);
  for (int i = 0; i < *N; ++i)
  {
    scanf("%d", &(ai[i]));
  }
  for (int i = 0; i < *M; ++i)
  {
    scanf("%d", &(bi[i]));
  }
}


// load the following style input 
// M
// c1 d1 c2 d2 ... cM dM 
// 
// note: ci di should be allocated
void load_ci_di(int* M, int ci[], int di[])
{
  scanf("%d", M);
  for (int i = 0; i < *M; ++i)
  {
    scanf("%d", &(ci[i]));
    scanf("%d", &(di[i]));
  }
}





//以下 使いそうな関数。課題で利用してOK
int k_max(int a, int b)
{
  return (a>=b)?a:b;
}

int k_swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}



