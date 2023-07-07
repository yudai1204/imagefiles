/*P4-5 switch,enum(他)(列挙enumeration)基礎情報演習1A*/
#include <stdio.h>
//タイプ:animal
//変数:dog,cat,cow,pig
//但し{----}とすると初期値0,1,2,3…が割り当てられる。
// dog=0,cat=1,cow=2,pig=3
enum animal
{
    dog,
    cat,
    cow,
    pig
};

int main(void)
{
    printf("/****P4-5:switch,enum****\n");
    printf("switch:\n数0~3を入力して下さい\n");

    int sw;
    scanf("%d", &sw);
    switch (sw)
    {
    case 0:
        printf("0を入力した\n");
        break;
    case 1:
        printf("1を入力した");
        break;
    case 2:
        printf("2を入力した");
        break;
    case 3:
        printf("3を入力した");
        break;
    default:
        printf("指定外の入力です\n");
        break;
    }

    printf("enum:\n動物の番号を選んでください\n");
    while (1)
    {
        int num;
        printf("0=dog,1=cat,2=cow,3=pig,他:終了\n");
        scanf("%d", &num);
        if ((num < 0) || (3 < num))
        {
            printf("enum終了\n");
            break;
        }
        else
        {
            enum animal an = (enum animal)num;
            if (an == pig)
                printf("**ブー**\n");
            else if (an == cat)
                printf("**ニヤン**\n");
            else if (an == cow)
                printf("**モー**\n");
            else if (an == dog)
                printf("**ワン**\n");
        }
    }

    // cast演算子
    double x = 12.345;
    float z = 12.34f;
    int i = (int)x;
    float y = (float)2000;
    printf("cast演算子\ni=%d,x=%15.12ff,x=%e,y=%9.4f\n", i, x, x, y);
    // 15.12は「印刷幅小数点以下の桁数」15か16または15より小さい数値でどう変わるか

    printf("(int):2.8=%d (int)(-0.8)=%d (int)(-2.8)=%d\n", (int)2.8, (int)(-0.8), (int)(-2.8));
    printf("*/\n");
    return 0;
}
