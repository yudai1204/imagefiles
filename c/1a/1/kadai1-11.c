#include <stdio.h>
int arr[3];
int print_array3(int* arr){
    int i;
    printf("arr[]={ ");
    for( i=0 ; i<3 ; i++ )
        printf("%d ",arr[i]);
    printf("}\n");
    return 0;
}
//n番目のかご(arr[n-1])、tama:入れる最大数、rest:玉の残り
//1番目のカゴに2つ入れたら2番目のカゴに入る最大数は2で残りは3
int func(int n,int tama,int rest){
    if(n==4){
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
    printf("3つのkagoに5つの玉を入れるプログラム\n");
    func(1,5,5);
}