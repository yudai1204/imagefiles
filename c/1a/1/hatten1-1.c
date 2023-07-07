#include <stdio.h>
int arr[5];
int bask,ball;
int print_array3(int* arr){
    int i;
    printf("arr[]={ ");
    for( i=0 ; i<bask ; i++ )
        printf("%d ",arr[i]);
    printf("}\n");
    return 0;
}
//n番目のかご(arr[n-1])、tama:入れる最大数、rest:玉の残り
//1番目のカゴに2つ入れたら2番目のカゴに入る最大数は2で残りは3
int func(int n,int tama,int rest){
    if(n==bask+1){
        if(rest==0){
            print_array3(arr);
            return 0;
        }else{
            return 0;
        }
    }for(int k = tama;k>=0;k--){
        arr[n-1]=k;
        int newrest = rest - k;
        func(n+1,k,newrest);
    }
    return 0;
}
int main(){
    printf("How many Baskets?(max 5) :");
    scanf("%d",&bask);
    printf("How many Balls? :");
    scanf("%d",&ball);
    printf("%d個のkagoに%d個の玉を入れるプログラム\n",bask,ball);
    func(1,ball,ball);
}