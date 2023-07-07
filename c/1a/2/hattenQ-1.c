#include <stdio.h>
#define SQUARE_SIZE 6
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

int main(void){
    int x,y,i;
    //ar初期化
    for(i=0;i<SQUARE_SIZE*SQUARE_SIZE;i++)
        ar[i%SQUARE_SIZE][i/SQUARE_SIZE] = 0;
    ar[1][2]=1;
    /*
    //見やすく表示する関数
    for(i=0;i<SQUARE_SIZE*SQUARE_SIZE;i++){
        if(!(i%SQUARE_SIZE))
            printf("|\n");
        if(check_queen(i/SQUARE_SIZE+1,i%SQUARE_SIZE+1))
            printf(" ");
        else
            printf("x");
        
    }printf("|\n");
    */
    //無限ループ
    while( 1 ){
        printf("入力 :");
        scanf("%d %d",&x,&y);
        if(check_queen(x,y))
            printf("success\n");
        else
            printf("fail\n");
            
        
    }
    return 0;
}