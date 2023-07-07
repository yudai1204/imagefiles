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
    int arr[3];
    int sum = 0;
    for (int k1 = 5;k1 >= 0; k1--){
        for (int k2 = 5;k2 >= 0; k2--){
            for (int k3 = 5;k3 >= 0; k3--){
                arr[0] = k1;
                arr[1] = k2;
                arr[2] = k3;
                if (k1 < k2) break;
                if (k2 < k3) continue;
                if (k1 + k2 + k3 == 5) print_array3(arr);
            }
        }
    }
}