#include <stdio.h>
int main(void){
    int k = 0 , sum = 0;
    while(1){
        k++;
        if(k>20) break;
        if ( k%2 && k%3 ) sum+=k;
        else continue;
    }
    printf("sum = %d\n",sum);
    return 0;
}