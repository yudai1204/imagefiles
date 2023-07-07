#include <stdio.h>

int summation(int n1,int n2){
    if (n2 == n1)
        return n1;
    else
        return n2 + summation(n1,n2-1);
}
int main(void){
    int n1,n2;
    printf("N1 = ");
    scanf("%d",&n1);
    printf("N2 = ");
    scanf("%d",&n2);
    printf("sum from %d to %d = %d\n",n1,n2,summation(n1,n2));
    return 0;
}