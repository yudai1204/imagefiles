#include <stdio.h>
void f(int *arr){
    arr[2] = 2;
    arr[3] = 3;
    return;
}

int main(void){
    int arr[4];
    arr[0] = 0;
    arr[1] = 1;
    f(arr);
    printf("arr[]={ %d,%d,%d,%d }\n",arr[0],arr[1],arr[2],arr[3]);
    return 0;
}