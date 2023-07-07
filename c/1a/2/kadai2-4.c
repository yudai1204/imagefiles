#include <stdio.h>
#include "PLIB.h"

int main(void){
    printf("/****P2-4 (int) ****\n");
    int a = 12345;
    printf("sizeof(a)=%d &a=%p (&a = aのアドレス)*(%a)=%d (アドレス&aの中身=aの値)\n", sizeof(a), &a, *(&a));

    double y = 12.34;
    printf("sizeof(y)=%d &y=%p (&y = yのアドレス)\n", sizeof(y), &y);
    printf("補足：アドレス(pointer)はPC毎に異なります\n\n");

    a = 64;
    int b = -a;
    printf("a=%08x, a=", a); print_bitposition(a);
    printf("b=%08x, b=", b); print_bitposition(b);

    a = 15 * 256 *256 + 15 * 256 + 15;
    b = -a;
    printf("a=%08x\n", a); print_bitposition(a);
    printf("b=%08x\n", b); print_bitposition(b);

    int n = 2745;
    printf("10進数:n = %06d,%d\n", n, n);
    printf("16進数:n = %06x,%06X,%x,%X\n", n, n, n, n);
    printf("*/\n");
}