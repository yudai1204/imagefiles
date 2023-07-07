#include <stdio.h>
#include <math.h>
#include "PLIB.h"  //ceilingPの関数定義をPLIB.hに追加しておく
#define N 18       //データ数

int s[N]={3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};

int search_2_3(int,int,int *,int);

int main(void){
    double y=2.001,z=2.7;

    printf("/***アルゴリズム2.3**\n");
    printf("case-0:ceilingP(%f)=%d ceilingP(%f)=%d \n",y,(int)ceilingP(y),z,(int)ceilingP(z));
    int n=18;
    int m1=6;
    int m2=7;
    printf("n=%d,m1=%d,m2=%d\n",n,m1,m2);
    printf("case-1:ceilingP(n/m1)=%d,(int)ceilingP(n/m2)=%d\n",(int)ceilingP(n/m1),(int)ceilingP(n/m2));
    printf("case-2:(int)ceilingP((double)n/(double)m1)=%d,(int)ceilingP((double)n/(double)m2)=%d",(int)ceilingP((double)n/(double)m1),(int)ceilingP((double)n/(double)m2));

    while(1){
        printf("\n質問の数値Xとブロック数mを入力(例 18 5 (終了は 0 0))\n");
        int x,m;
        scanf("%d %d",&x,&m);
        if((m>N) || (m<=0) || (x==0)) break;
            int rc=search_2_3(x,m,s,N);
        printf("rc=%d",rc);
        if(rc>=0) printf("(s[%d]=%d)\n",rc,s[rc]);
        else      printf("(%d:Not found)\n",x);
    }
    printf("*/\n");
}

int search_2_3(int x,int m,int *s,int n){

    int k;
    k=ceilingP((double)(n)/m);
    //ステップ1:xを含むブロックの探索
    int j=0;
    while(j<=m-2){
        if(x<=s[(j+1)*k-1]) break;
        else j++;
    }
    //ステップ2:ブロック内の探索
    int i=j*k;
    int t=((j+1)*k-1<=n-1)?(j+1)*k-1:n-1;//小さい値を選択
    int cnt = 0;
    while(i<t){
        if(x<=s[i]) break;
        else i++;
    }
    if(x==s[i]) return i;
    return -1;
}
