#include <stdio.h>
void print_bitposition(int c){
    for(int i = 0;i<32;i++){
        int bit = ( c<<i < 0 ) ? 1 : 0;
        printf("%1d",bit);
    }
    printf("\n");
}
int main(){
    printf("/*** Review3 ***\n");
    print_bitposition(66561); /** 66561 = 65536 + 1024  +1*/
    char ch1 = 'j';
    char ch2 = 'p' - 'f';
    printf("\nch1 + 3 = %c, ch2 = %d\n\n", ch1 + 3, ch2);

    int b = 0x00ff0ff0, d = 0x0ff05c5c;
    printf("b AND d --->");
    print_bitposition(b & d);
    int p = b > d;
    printf("\n(b > d) = %d, 'a' < 'b' = %d\n\n", p, 'a'<'b');

    int s;
    unsigned int t;
    s = 0x00ffffff; printf("s = %08x", s); s=s>>8; printf("s = %08x\n\n", s);
    s = s << 16   ; printf("s = %08x", s); s=s>>8; printf("s = %08x\n\n", s);
    t = 0xffff0000; printf("t = %08x", t); t=t>>8; printf("t = %08x\n\n", t);

    printf("sizeof(ch1) = %d &ch1 = %p\n\n", sizeof(ch1), &ch1);
    printf("sizeof(b) = %d &b = %p\n\n", sizeof(b), &b);
    int n = 298; /*298 = 256 + 32 + 10*/
    printf("n = %04d, %d, %04x, %04X, %x\n", n, n, n, n, n);
    printf("*/\n");
}