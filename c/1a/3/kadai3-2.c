/* 課題3-2(構造体とその定義)基礎情報演習1A: */
#include <stdio.h>
#include <string.h>
int main(void){
    //kozo1→構造体名(タイプ;型枠)
    struct kozo1{
        int a;
        float b;
        char name[16];
    };

    //g1,g→構造体変数名(メモリ実体)
    //p=構造体変数を指すポインタ名(メモリ実体;4バイト長)
    struct kozo1 g1,g,*p;
    typedef struct{
        int a;
        double b;
        char name[16];
    }kozo2;
    kozo2 g2,*p2;

    printf("/*** P3-2(構造体とその定義) ****\n");
    printf("sizeof(struct kozo1)=%d,&g1=%p,&g1.a=%p,\n&g1.b=%p,&g1.name=%p\n",
            sizeof(struct kozo1),&g1,&g1.a,&g2.b,&g2.name);
    
    g2.a = 10;
    g2.b = 12.3;
    p2 = &g2;
    strcpy(g2.name , "shibaura");

    printf("g2.a=%d,g2.b=%f,g2.name=%s,\n\n",g2.a,g2.b,g2.name);
    printf("p2->a=%d,p2->b=%f,g1.name=%s\n\n",g1.a,g1.b,g1.name);

    /*構造体の代入，注意：構造体は正確な比較ができない（隙間を作るかどうかは処理系依存）*/
    g=g1;
    p=&g;
    printf("p->a=%d,p->b=%f,p->name=%s\n",p->a,p->b,p->name);
    printf("g.a=%d,g.b=%f,g.game=%s\n",g.a,g.b,g.name);
    printf("*/\n");
}