#include <stdio.h>
int main(void){
    printf("4月\n");
    printf(" sun mon tue wed thi fri sat\n");
    for ( int i = -4 ; i < 31 ; i++ ){
        if (i>0)
            printf("%4d",i);
        else 
            printf("    ");
        if ( !((i+5)%7) )
            printf("\n");
    }

    return 0;
}