/*課題6-5(教科書31貢)アルゴリズム2.9　与えられたデータを探索する手続き(ハッシュ法)*/
#include <stdio.h>
#define N 18
#define m 27

static int s[N] = {3, 4, 6, 7, 9, 11, 14, 15, 17, 18, 20, 23, 24, 26, 27, 29, 30, 32};
int hash(int);
int search(int, int *);
void make_htb(int *, int *);

int main(void)
{
    int htb[m];
    make_htb(s, htb);

    for (int i = 0; i < m; i++)
    {
        printf("htb[%2d]=%2d", i, htb[i]);
        if (((i + 1) / 7) * 7 == (i + 1))
            printf("\n");
    }
    //無い値の探索
    printf("\n探索するデータxを入力(半角英数)\n");
    int x;
    scanf("%d", &x);
    int rc = search(x, htb); //データの探索
    if (rc >= 0)
        printf("rc=%d(x=%d,htb[%d]=%d)", rc, x, rc, htb[rc]);
    else
        printf("rc=%d(**%d not found**)", rc, x);
    printf("\n*/\n");
}

int hash(int x)
{
    return (x % m);
}
int hk(int x,int k)
{
    return ( x + 3*(k-1)*x )% m;
}

void make_htb(int *s, int *htb)
{
    for (int i=0;i<m;i++)htb[i]=0; 
    for (int i = 0; i < N; i++)
    {
        int j = hash(s[i]);
        for (int k = 2;htb[j] != 0;k++)
            j = hk(s[i],k);
        htb[j] = s[i];
    }
}

int search(int x, int *htb)
{
    int j = hash(x);
    while ((htb[j] != 0) && (htb[j] != x))
        j = (j + 1) % m;
    if (htb[j] == x)
        return j;
    else
        return -1;
}
