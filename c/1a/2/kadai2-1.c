#include <stdio.h>
int main(void)
{
    int data[4] = {4,-4,256,66560}; //66560(65536 + 1024)
    printf("/***P2-1(準備:int内のビットを計算)****\n");
    for(int j = 0;j<4;j++){
        int w = data[j];
        for(int i = 0;i<32;i++){
            if(w<0)printf("1");//w<0 → wの符号ビット==1
            else printf("0");//w>=0 → wの符号ビット==0
            w=w<<1;         //w(の内容)を左1ビットシフト
        }
        printf("\n");
    }
    printf("\n\n***10進数(16進数)とASCII文字との対応****");
    for(int i = 32;i<127;i++){
        if(i==(i/8)*8) printf("\n");
        printf("%3d(%02x)%c",i,i,i);
    }
    //同じ値iを10進数3桁、16進数2桁、文字として印字
    char ch1 = 'A';
    char ch2 = ch1 + 5;
    char ch3 = 'a'-'z';
    //charは長さ8ビットの符号付整数として扱える
    printf("\n\nch1=%c,ch1=%d,ch2=%c,ch3=%d",ch1,ch1,ch2,ch3);
    printf("\n*/\n");
}