#include <stdio.h>
#define N 5

typedef struct{
    double r;
    double i;;
}complex;

typedef struct{
    char name[20];
    double height;
    double weight;
}record;

complex plus(complex,complex);
record *kenkou(int);

int main(void)
{
    printf("/**** P4-1（構造体と関数）****\n");
    complex x,y;
    x.r=6.0; x.i=3.0;
    y.r=5.0; y.i=6.0;
    complex zp=plus(x,y);
    printf("zp.r=%6.2f,zp.i=%6.2f\n",zp.r,zp.i);

    int no;
    printf("1~%dを入力\n",N);
    scanf("%d",&no);

    record *p; p = kenkou( no );
    printf("%s 身長：%5.2fcm 体重%4.2fKg\n", p->name,p->height,p->weight);
    printf("*/");
}

complex plus(complex x, complex y)
{
    static complex temp;
    temp.r = x.r + y.r;
    temp.i = x.i + y.i;
    return temp;
}

record *kenkou(int who)
{
    static record*temp;
    static record data[N] = {
    {"Abe", 178.8, 76.5},{"Denny",163.5,56.2},
    {"Jack",169.3,58.7},{"Merry",172.2,52.0},
    {"Washington",158.5,63.2} 
    };
    temp = &data[who-1];
    return temp;
}