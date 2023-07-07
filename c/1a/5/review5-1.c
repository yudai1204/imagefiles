#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    printf("/** Review05 **----空欄に適切な数値などを書き込みなさい---\n");

    char mn1[24],mn2[20];
    char mn3[] = "abcdefghij", mn4[30] = "Hellow!";
    static char a[3][12] = {"Hanada","Nagashima","Koizumi"};

    strcpy(mn1,"Tokyo-Yokohama");
    printf("(1)mn1=%s:",mn1);
    printf("strlen(mn1)=%d,strlen(mn3)=%d\n",strlen(mn1),strlen(mn3));
    strcpy(mn1,a[0]);

    printf("(2)mn1=%s,a[1]=%s:",mn1,a[1]);
    printf(" strcmp(mn1,a[1]=%d\n",strcmp(mn1,a[1]));

    printf("(3) 名をローマ字(英数半角)で入力してください\n");
    scanf("%s",mn2);
    strcat(mn4,mn2);
    printf("%s\n",mn4);

    printf("(4)enum:\n動物の番号を選んでください\n");
    printf("0=dog,1=cat,2=cow,3=pig\n");
    int num;
    scanf("%d",&num);
    enum animal{cat,cow,pig,dog};
    enum animal an = (enum animal) num;
    if (an == pig)printf("**ブー**\n");
    else if (an == cat)printf("**ニヤン**\n");
    else if (an == cow)printf("**モー**\n");
    else if (an == dog)printf("**ワン**\n");

    printf("(5)\n");
    char a1='V', b1='f',c1='$',d1='7',e1=' ';
    printf("isalpha(%c)=%d ",c1,isalpha(c1));
    printf("isalpha(%c)=%d ",a1,isalpha(a1));
    printf("isspace(%c)=%d ",a1,isspace(a1));
    printf("isspace(%c)=%d\n",e1,isspace(e1));
    printf("isdigit(%c)=%d ",b1,isdigit(b1));
    printf("isdigit(%c)=%d ",d1,isdigit(d1));

    char str1[]="abCDdeFGhijkxxx!#$#&xxYYzzPp",str2[30];
    for(int i=0; i<sizeof(str1); i++) str2[i]=toupper(str1[i]);
    printf("str2=%s\n",str2);
    for(int i=0; i<sizeof(str1); i++) str1[i]=tolower(str2[i]);
    printf("str1=%s\n",str1);
    printf("*/\n");
}
