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
    printf("/****P2-2(ビット演算)****\n");
    int b = 0x00ff0f0f;
    int d = 0x0ff03c3c;
    printf("b = 0x00ff0f0f --> ");print_bitposition(b);
    printf("d = 0x0ff03c3c --> ");print_bitposition(d);
    printf("b OR d ----------> ");print_bitposition(b|d);
    printf("b AND d ---------> ");print_bitposition(b & d);
    printf("b (+) d ---------> ");print_bitposition(b ^ d); /* ビット単位の排他的論理和 */
    printf("~b --------------> ");print_bitposition(~b);

    /* 複合代入演算子 */
    int p1 = 0x00ff0f0f;
    int p2 = 0x00ff0f0f;
    int p3 = 0x00ff0f0f;
    int q =  0x0ff03c3c;
    p1 |= q; printf("p1 --> ");print_bitposition(p1);
    p2 &= q;printf("p2 --> ");print_bitposition(p2);
    p3 ^= q; printf("p3 --> ");print_bitposition(p3);

    /* 例えばp&=q;はp=-&q;と同じ */
    int p = b == d;
    printf("(b==d)=%d\n",p);
    p=b<d;
    printf("(b<d)=%d\n",p);
    printf("*/\n");
    return 0;
}