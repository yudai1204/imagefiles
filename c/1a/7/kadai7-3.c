#include <stdio.h>
#define N 18
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int BinarySearch(int, int*, int, int);
int main(void){
    int rc, x;
    printf("/*** 2章・問1 **\n");
    printf("質問の数値xを入力してください(半角)\n");
    scanf("%d",&x);
    rc = BinarySearch(x, s,0,N-1);
    printf("rc = %d", rc);
    if (rc >= 0) printf("(x=%d, s[%d]=%d)\n", x, rc, s[rc]);
    printf("*/\n");
}
int BinarySearch(int x, int *s, int i, int j){
    int mid, left, right;
    left = i;
    right = j;
    mid = (left + right) / 2;
    printf("left = %d, right = %d, mid = %d\n", left, right, mid);
    if (s[mid] == x) return mid;
    if (x < s[mid]) right = mid -1;
    else left = mid + 1;
    if (left > right) return -1;
    return BinarySearch(x, s, left, right);
}