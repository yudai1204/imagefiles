/* 発展5-1 第1章ー演習問題 問4(教科書14頁) */
#include <stdio.h>
#define N 3
#define M 6
int a[N] = {4,6,9};
int b[M] = {2,5,8,12,16,18};
int c[N+M];
int main(void){
    int i=0,j=0;
    for(int k=0 ; k<N+M ; k++){
        if( i < N && j < M){
            if( a[i] < b[j] ){
                c[k] = a[i++];
            }else{
                c[k] = b[j++];
            }
        }else if(i >= N){
            c[k] = b[j++];
        }else if(j >= M){
            c[k] = a[i++];
        }
        printf("i=%d j=%d k=%d: c[%d]=%d\n",i,j,k,k,c[k]);
    }
    return 0;
}