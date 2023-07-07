#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000
int s[N];
int search(long int,int*,long int);
void dataset(){
    long int k;
    for(k = 0; k < N; k++)s[k]=k;
}
int main(void){
    int k,sum;
    long int x;
    printf("/** 1000000個のデータの平均探索回数 **");
    dataset();
    srand((unsigned)time(NULL));
    sum = 0;
    for(k=0;k<100;k++){
        x = (rand()%1000)*1000 + rand()%1000;
        sum = sum + search(x,s,N);
    }
    printf("平均探索回数:%f\n",(double)sum/100.0);
    printf("*/\n");
}

int search(long int x,int *s,long int n){
    int left,right,mid,count = 0;
    printf("start search %d\n",x);
    left = 0;
    right = n-1;
    do{
        count++;
        mid = (left+right)/2;
        if(x<s[mid])right = mid-1;
        else left = mid+1;
    }while((x!=s[mid])&&(left<=right));
    if(x==s[mid])return count;
    printf("Error: Never come here\n");
    return -1;
}