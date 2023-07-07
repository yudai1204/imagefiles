#include <stdio.h>
#define N 18 //N=データ数
int a[N]={10,-4,-8,4,5,-3,6,7,8,-4,9,-5,20,-6,4,-8,9,-3};

// #define N 4
//int a[N] = {-1,-10,-3,-5};
// int a[N] = {2,-3,3,-2};


int sum(int i,int j){
    if( i == j ){
        return a[i];
    }else{
        return(sum(i,j-1) + a[j]);
    } 
}
int main(void){
    int summax=a[0],maxi=0;
    int summin=a[0],mini=0;
    for( int i=0 ; i<N ; i++ ){
        if(sum(0,i) >= summax){
            summax=sum(0,i);
            maxi=i;
        }
    }
    for( int i=0 ; i<=maxi ; i++ ){
        if(sum(0,i) <= summin){
            summin=sum(0,i);
            mini=i;
        }
    }
    int maximum=summax-summin;
    mini++;
    if(summax==summin){
        maximum = summin;
        mini--;
    }
    printf("区間 a[%d]～a[%d]の和が最大: 最大値=%d\n",mini,maxi,maximum);
}