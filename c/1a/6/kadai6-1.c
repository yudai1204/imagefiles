#include <stdio.h>
#define N 8
int s[N]={13,30,42,87,10,60,50,25};
int search_2_1(int,int *,int);

int main(void){
    printf("/***アルゴリズム2.1**\n");
    printf("(1) rc=%d\n",search_2_1(60,s,N));
    printf("(2) rc=%d\n",search_2_1(55,s,N));
    printf("*/\n");
}

int search_2_1(int x,int *s,int n){
    int i=0;
    do{
        if(x==s[i])return i;
        else i=i+1;
    }while(i<n);
    return -1;
}
