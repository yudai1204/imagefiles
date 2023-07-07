#include <stdio.h>
int print_array3(int* arr){
    int i;
    printf("arr[]={ ");
    for( i=0 ; i<3 ; i++ )
        printf("%d ",arr[i]);
    printf("}\n");
    return 0;
}
int main(void){
    int i,k1,k2,k3,arr[3],sum;
    sum = 0;
    for ( k1=5; k1>=0; k1-- ){
        for ( k2=5-k1; k2>=0; k2-- ){
            for ( k3=5-k1-k2; k3>=0; k3-- ){
                arr[0] = k1;
                arr[1] = k2;
                arr[2] = k3;
                if (k1+k2+k3==5 && k1>=k2 && k2 >= k3) print_array3(arr);
            }
        }
    }
}