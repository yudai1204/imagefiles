#include <stdio.h>
//#define N 18 //N=データ数
//int a[N]={10,-4,-8,4,5,-3,6,7,8,-4,9,-5,20,-6,4,-8,9,-3};

#define N 4
// int a[N] = {-1,-10,-3,-5};
int a[N] = {2,-3,3,-2};


int sum(int i,int j){
    if( i == j ){
        return a[i];
    }else{
        return(sum(i,j-1) + a[j]);
    } 
}
int main(void){
    int max=a[N-1],maxi=N-1,maxj=N-1;
    for(int j=N-1 ; j>=0 ; j-- ){
        for(int i=j ; i>=0 ; i--){
            if( sum(i,j) > max ){
                max = sum(i,j);
                maxi = i;
                maxj = j;
            }
        }
    }
    printf("区間 a[%d]～a[%d]の和が最大: 最大値=%d\n",maxi,maxj,max);
}