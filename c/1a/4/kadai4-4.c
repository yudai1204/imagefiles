#include <stdio.h>
#include <string.h>        //strcat,strcpy,strlen,strcmp,%s

//文字列配列の初期値設定
char a[3][12]={"Tanaka","Nagashima","Yoshida"};

int main(void){
    printf("/***P4-4(文字列関数)***\n");

    //NOTE:strcpy(string copy)文字列のコピー
    //NOTE:strlen(格納してある)文字の長さ
    //NOTE:strcmp(string compare)文字の比較

    char nm1[12],nm2[20];
    char nm3[]="abcdefghij",nm4[30]="Hellow!";
    printf("sizeof(nm1)=%d,sizeof(nm3)=%d\n",sizeof(nm1),sizeof(nm3));

    strcpy(nm1,"Shibaura");
    printf("(1)nm1=%s\n",nm1);
    printf("strlen(nm1)=%d,strlen(nm3)=%d\n",strlen(nm1),strlen(nm3));

    strcpy(nm1,nm3);
    printf("(2)strlen(nm1)=%d,strlen(nm3)=%d,nm1=%s\n",strlen(nm1),strlen(nm3),nm1);

    strcpy(nm1,a[0]);
    strcpy(nm2,a[1]);
    strcpy(nm3,a[2]);//a[0],a[1],a[2]は何か?

    printf("(3)nm1=%s,nm2=%s,nm3=%s\n",nm1,nm2,nm3);
    printf("strcmp(nm1,nm1)=%d(nm1==nm1)\n",strcmp(nm1,nm1));
    printf("strcmp(nm1,nm2)=%d(nm1>nm2)\n",strcmp(nm1,nm2));
    printf("strcmp(nm2,nm3)=%d(nm2<nm3)\n",strcmp(nm2,nm3));

    //strcat(string catenation)文字の結合
    printf("(5)名をローマ字(英数半角)で入力して下さい\n");
    scanf("%s",nm2);  //printf("nm2=%s\n",nm2);
    strcat(nm4,nm2);
    printf("%s\n",nm4);

    //x=y?p:q(yが真ならばp,yが偽ならばqをxに代入)
    int p=10,q=20,selection;
    selection=(p>q)?(p+1):(q-5);
    printf("(6)(p>q)?(p+1):(q-5);selection=%d(p=%d,q=%d)\n",selection,p,q);
    printf("*/\n");
}
