#include <stdio.h>
void print_bitposition(int w){
    for(int i=0;i<32;i++){
        if(w<0)printf("1");
        else printf("0");
        w=w<<1;
    }
    printf("\n");
}
