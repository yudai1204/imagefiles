#include <stdio.h>
#define N 18 //データ数
#define m 27 //ハッシュ表のサイズ
static int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};//データ
int hash(int);

int main(void)
{
    int htb[m];
    printf("/***アルゴリズム2.8**\n");
    //htbを初期化
    for(int i=0;i<m;i++)htb[i]=0;

    for(int i=0;i<N;i++)
    {
        int j=hash(s[i]);//ハッシュ値を計算
        while(htb[j]!=0)//!!空欄!! //ハッシュ票で空いている場所を探す
            j=(j+1)%m;        //!!空欄!! //空いていなければ右隣へ
        htb[j]=s[i]; //最初の空き場所に値を格納
    }

    printf("(教科書32頁の図2.7参照)\n");

    for(int i = 0;i < m;i++)
    {
        printf("htb[%2d]=%2d ",i,htb[i]);
        if(((i + 1) / 7) * 7 == (i + 1) ) printf("\n");
    }
    printf("\n*/\n");
}

int hash(int x)
{
    return(x % m);
}