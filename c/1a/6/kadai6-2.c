/* 課題6-2(教科書19~20頁)アルゴリズム 2.2 逐次探索法 */
#include <stdio.h>
#define N 18 //データ数
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int search_2_2(int,int*,int);

int main(void){
    printf("/*** アルゴリズム 2.2**\n");
    printf("(1)rc=%d\n",search_2_2(23,s,N));
    printf("(2)rc=%d\n",search_2_2(16,s,N));
    printf("*/\n");
}
int search_2_2(int x,int *s,int n){
    int i = 0;
    do{
        if( s[i] == x)break;
        else i++;
    }while(i<n);
    if(i<n-1)return i;
    return -1;
}