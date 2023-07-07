#include <stdio.h>
void print_bitposition(int w){
    for(int i=0;i<32;i++)
    {
        if(w<0)printf("1");
        else printf("0");
        w=w<<1;
    }
    printf("\n");
}
int main(void){
    int x;
    while(1){
        printf("Input x:");
        scanf("%d",&x);
        printf("x ---> ");print_bitposition(x);
    }
    return 0;
}