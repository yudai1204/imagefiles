#include <stdio.h>
void print_hexa(int);
void print_c(unsigned char);
void print_bitposition(int);

//mainで呼び出す関数の定義がmainの後ろの場合にはプロトタイプ宣言が必要
int main(void){
    printf("/**** P2-3(シフト演算)****");
    printf("\nint a:(算術シフト:右シフトはsign bitが続く)\n");
    int a;
    a = 0x0fffffff; print_hexa(a);
    a = a >> 12; print_hexa(a);
    a = a << 16; print_hexa(a);
    a = a >> 16; print_hexa(a);
    a = a << 20; print_hexa(a);
    a = a >> 12; print_hexa(a);
    //↑1行に複数命令を記述するマルチステートメント。
    //可読性が明確に上がる場合は利用する。
    printf("unsigned int b;(論理シフト:右シフトは'0'が続く)\n");
    unsigned int b;
    b = 0x0fffffff; print_hexa(b);
    b = 0x0fffffff; print_hexa(b);
    b = b >> 12; print_hexa(b);
    b = b << 16; print_hexa(b);
    b = b >> 16; print_hexa(b);
    b = b << 20; print_hexa(b);
    b = b >> 12; print_hexa(b);
    /* int aの右シフト→aのsign bit続く。unsigned int bは'0'*/
    printf("\nc:符号なし文字");
    unsigned char c;
    c = -1;     print_c(c);
    c = c << 3; print_c(c);
    c = c >> 2; print_c(c);/*8ビットシフト→16進数2桁シフト*/

    char ch = 97;
    printf("\nch=%d(hexa %x)ch=%c ch+7=%c\n",ch,ch,ch,ch+7);
    printf("*/\n");
}
void print_hexa(int t)
{
    printf("(hex:%08X)%10d;",t,t);
    print_bitposition(t);
}
/*勉強:%08x→小文字*/
void print_c(unsigned char t) /*勉強:%8d→上位'0'の印刷抑止*/
{
    printf("(hex:%02X)%03d;",t,t);
}
void print_bitposition(int w){
    for(int i=0;i<32;i++){
        if(w<0)printf("1");
        else printf("0");
        w=w<<1;
    }
    printf("\n");
}
/****P2-3(シフト演算)****(問題:下記空欄への出力値を予測して確認)
    int a(算術シフト:右シフトは sign bitが続く)
    (hex:0FFFFFFF) 268435455;
    (hex:0000FFFF) 65535;
    (hex:FFFF0000) -65536;
    (hex:FFFFFFFF) -1;
    (hex:FFF00000) -1048576;
    (hex:FFFFFF00) -256;
    unsigned int b:(論理シフト：右シフトは'0'が続く)
    (hex:0FFFFFFF) 268435455;
    (hex:0000FFFF) 65535;
    (hex:FFFF0000) -65536;
    (hex:0000FFFF) 65535;
    (hex:FFF00000) -1048576;
    (hex:000FFF00) 1048320;
    c:符号なし文字(hex:FF)_____;(hex:F8)___;(hex:3E)___;
    ch=__(hexa__)ch=__ch+7=__
*/