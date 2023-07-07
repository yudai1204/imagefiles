#include <stdio.h>
#define true 1
#define false 0
#define SQUARE_SIZE 30
#define sq(x) (x*x)
int ar[SQUARE_SIZE][SQUARE_SIZE];

int check_queen(int x,int y){
    int i;
    x--;
    y--;
    for( i=0 ; i<SQUARE_SIZE ; i++ ){
        if (ar[x][i] || ar[i][y]) //同じ行か列にいるかどうか
            return 0;
    }
    for(i=0 ; x-i>=0 && y-i>=0 ; i++ ){
        if (ar[x-i][y-i])
            return 0;
    }
    for(i=0 ; x+i<SQUARE_SIZE && y+i<SQUARE_SIZE ; i++){
        if (ar[x+i][y+i])
            return 0;
    }
    for(i=0 ; x+i<SQUARE_SIZE && y-i>=0 ; i++){
        if (ar[x+i][y-i])
            return 0;
    }
    for(i=0 ; x-i>=0 && y+i<SQUARE_SIZE ; i++){
        if (ar[x-i][y+i])
            return 0;
    }
    return 1;
}

void display_queen(void){
    int i;
    printf(" ");
    for(i=0 ; i < sq(SQUARE_SIZE) + SQUARE_SIZE ; i++){
        printf("% 2d",(i/(SQUARE_SIZE)) ? ar[i/SQUARE_SIZE-1][i%SQUARE_SIZE] : i+1);
        if(i%SQUARE_SIZE == SQUARE_SIZE-1 && i/SQUARE_SIZE<SQUARE_SIZE)
            printf("\n%d",i/SQUARE_SIZE+1);
    }
    printf("\n");
    return;
}
int countNqueen(int x ,int n){

}
//デバッグ用関数
void display_ok(void){    
    int i;
    for(i=0;i<sq(SQUARE_SIZE);i++){
        if(!(i%SQUARE_SIZE) && i)
            printf("|\n");
        if(check_queen(i/SQUARE_SIZE+1,i%SQUARE_SIZE+1))
            printf("  ");
        else
            printf(" x");
        
    }printf("|\n");
    return;
}

int main(void){
    int x,y,i;
    //ar初期化
    for(i=0 ; i<sq(SQUARE_SIZE) ; i++)
        ar[i%SQUARE_SIZE][i/SQUARE_SIZE] = 0;
    //無限ループ
    while( 1 ){
        display_ok();
        display_queen();
        printf("入力 :");
        scanf("%d %d",&x,&y);
        if(check_queen(x,y)){
            printf("success\n");
            ar[x-1][y-1]=1;
        }else{
            printf("fail\n");
        }
    }
    return 0;
}