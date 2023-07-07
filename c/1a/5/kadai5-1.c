/* 課題5-1 教科書5頁アルゴリズム 1.1 株式投資における最大売却益(A)方式 */
/* 基本的な方式 オーダーはn^2 */
#include <stdio.h>
#define N 24

int sp[N] = {   /*毎月の株価:教科書4頁の表を参考に定めた値*/
    1670,1750,1280,1080,1700,1850,2030,1870,1920,1750,1400,1560,
    1070,770,1150,1070,1400,1120,1050,1500,1400,1740,2050,1780};

int main(void){
    printf("/*** アルゴリズム1.1 **");
    int mxp = sp[1]-sp[0];  /* 利益の最大値mxpを初期化 */
    for(int i=0 ; i<=N-2 ; i++){
        for(int j=i+1 ; j<=N-1 ; j++){
            int d = sp[j] - sp[i];/*売却益=売値-買値*/
            if(d > mxp)/*今まで以上の売却益であればmxpの値を更新する*/
                mxp = d;
        }
    }
    printf("\nmxp=%d \n*/\n",mxp);
}