#include <stdio.h>
#include <string.h>
struct kozo1{
  int a;
  float b;
  char name[16];
};

struct kozo1 g1,g,*p;

typedef struct any{
  int a;
  double b;
  char name[16];
}kozo2;

kozo2 g2,g3,*p2;

typedef unsigned int P32;
typedef short int S16;

static int A[4]={34,33,32,31};
static int B[3][4]={11,12,13,14,21,22,23,24,31,32,33,34};
int C[4];
static int a[5]={1,2,3,4,5},b[5]={19,18,17,16,15};

int *sub(int p[],int q[])
{
  int i;
  static int wk[5];
  for(i=0;i<5;i++)wk[i]=p[i]-q[i];
  return wk;
}

int main(void)
{
  int a1,*a2;
  int i,j,*v;
  double d1,*d2;
  char ch1[10]="abcdef",ch2[]="abcdef";

  printf("/***Review04***\n");
  printf("step1:\n");
  printf("sizeof(P32) =%d,sizeof(S16) =%d\n" ,sizeof(P32) ,sizeof(S16));
  printf("sizeof(float) =%d,sizeof(double) =%d\n" ,sizeof(float) ,sizeof(double));
  printf("sizeof(ch1) =%d,sizeof(ch2) =%d\n\n" ,sizeof(ch1) ,sizeof(ch2));
  a1=20; a2=&a1; printf("a1=%d,*a2+5=%d" ,a1,*a2+5);
  d1=45.6; d2=&d1; printf("d1=%f,*d2=%f\n" ,d1,*d2-0.3);

  printf("step2:\n");
  printf("A=%p\n" ,A);
  for(j=0;j<4;j++)printf("&A[%d]=%p" ,j,&A[j]);
  printf("\n");
  for(i=0;i<3;i++)
  {
    for(j=0;j<4;j++)
      printf("B[%d][%d]=%2d" ,i,j,B[i][j]);
    printf("\n");
  }

  printf("step3:\n");
  for(j=0;j<4;j++)C[j]=B[2][j]+300;
  for(j=0;j<4;j++)printf("C[%d]=%3d" ,j,C[j]);
  v=sub(a,b);
  for(i=0;i<5;i++)printf("v[%d]=%d" ,i,v[i]);

  printf("\nstep4:\n");
  printf("sizeof(struct kozo1)=%d\n&g1=%p,&g1.a=%p,&g1.b=%p,&g1.name=%p\n" ,sizeof(struct kozo1),&g1,&g1.a,&g1.b,&g1.name);
  g2.a=10;
  g2.b=12.3;
  strcpy(g2.name," shibaura");

  p2=&g2;
  printf("p2->a=%d p2->b=%f p2->name=%s\n" ,p2->a,p2->b,p2->name);
  g3=g2;
  g3.a=g3.a+10;
  printf("g3.a=%d g3.b=%f g3.name=%s\n" ,g3.a,g3.b,g3.name);
  printf("*/\n");
}
