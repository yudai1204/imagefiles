#include <stdio.h>
#include <stdlib.h>
#define Number 20

int main(void)
{
  printf("/**** P4-2 (メモリの動的確保と解放) ****\n");
  int *ptr; ptr=(int*)malloc(sizeof(int) *Number);
  if(ptr!=NULL)
  {
    printf("ptr=%p\n",ptr);
    for(int i=0;i<Number;i++)
    {
      ptr[i]=i*10+1;
      printf("%03d",ptr[i]);
    }
  }
  free(ptr);
  printf("\n*/\n");
}
