#include <stdio.h>
#define N 18
int s[N] = {3,4,6,7,9,11,14,15,17,18,20,23,24,26,27,29,30,32};
int search_2_7(int, int*, int);
int main(void){
    int rc, x;
    printf("/***アルゴリズム2.7**\n");
    printf("質問の数値xを入力してください(半角)\n");
    scanf("%d", &x);

    rc = search_2_7(x, s, N);
    printf("rc = %d", rc);
    if (rc >= 0) printf("(x=%d, s[%d]=%d)\n", x, rc, s[rc]);
    else printf("(%d: Not Found)\n", x);
    printf("*\n");
}
int search_2_7(int x, int *s, int n){
    int left, right, mid;
    if (x<s[0] || x>s[n-1]) return -1;
    left = 0;
    right = n-1;
    printf("Trace:: ");
    do{
        mid = (left + right) / 2;
        printf("s[%d]=%d ", mid, s[mid]);
        if (x < s[mid]) right = mid -1;
        else left = mid + 1;
    }while(left<=right);
    printf("\n");
    if(x == s[right]) return right;
    else return -1;
}