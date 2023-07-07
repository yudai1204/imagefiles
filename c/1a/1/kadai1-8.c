#include <stdio.h>
int f(int n){
    if (!n)
        return 0;
    else if ( n%2 && n%3 ) 
        return n + f(n-1);
    else
        return f(n-1);
}

int main(void){
    printf("sum = %d\n",f(20));
    return 0;
}