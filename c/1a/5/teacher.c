#include <stdio.h>
// #define N 18
// int a[N]={10,-4,-8,4,5,-3,6,7,8,-4,9,-5,20,-6,4,-8,9,-3};

#define N 4
int a[N] = {-1,-10,-3,-5};
//int a[N] = {2,-3,3,-2};

int main(void){
    int temp;
    int sum_0i = 0;
    int min_0j = 0;
    int max =a[0];
    int high =0;
    int low = 0;
    int lowtmp = 0;
    for(int i=0;i<N;i++){
        sum_0i = sum_0i +  a[i];
        if (sum_0i < min_0j){
            min_0j = sum_0i;
            lowtmp = i+1;
        }
        temp = sum_0i - min_0j;
        if(max < temp){
            max = temp;
            high = i;
            low = lowtmp;
        }
    }
    printf("区間a[%d]~a[%d]の最大値=%d\n",low,high,max);
}