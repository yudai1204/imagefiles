#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
int sp[N],printflag;
void data_set()
{
    sp[0]=2000;
    for(int i=1;i<N;i++)
    {
        int d1=rand()%2;
        int d2=rand()%10;
        if     (sp[i-1]>5000)d1=1;
        else if(sp[i-1]<500)d1=0;

        if(d1==0)sp[i]=sp[i-1]+sp[i-1]*d2/100;
        else     sp[i]=sp[i-1]-sp[i-1]*d2/100;
    }
}
int modify_value(long int longi)
{
    if(longi<N)return sp[longi];
    long int dd=longi/N;
    long int d1=dd % 2;
    long int d2=(dd +(longi % 10)) % 10;

    if(d1==0)return sp[longi % N]+sp[longi % N] * d2 / 100;
    else     return sp[longi % N]-sp[longi % N] * d2 / 100;

}
int main(void)
{
    data_set();
    srand(time(NULL));

    while (1)
    {
        int pat,NN;
        printf("O(n):1 O(n*n):2 ?");
        scanf("%d" ,&pat);
        printf("NN=");
        scanf("%d" ,&NN);

        if(pat == 1)
        {
            clock_t start=clock();
            printf("/*** アルゴリズムO(n)**");
            int mxp =sp[1]-sp[0];
            int msf=sp[0];
            for(long int longi=1;longi <= NN-1;longi++)
            {
                int xi=modify_value(longi);
                int d=xi-msf;
                if(d>mxp)mxp=d;
                if(sp[longi%10]<msf)msf=sp[longi%10];
            }
            clock_t end=clock();
            printf("\nmxp=%d \n*/\n" ,mxp);
            printf("order=O(n) NN=%d time=%.2f秒\n" ,NN,(double)(end-start)/CLOCKS_PER_SEC);
        }
        else if(pat == 2)
        {
        printf("/*** アルゴリズムO(nn)**");
        clock_t start=clock();
        int mxp=sp[1]-sp[0];
        for(long int longi=0;longi<=NN-2;longi++)
        {
            int xi=modify_value(longi);
            for(long int longj=longi+1;longj<=NN-1;longj++)
            {
                int xj=modify_value(longj);
                int d=xj-xi;
                if(d>mxp)mxp=d;
            }
        }
        clock_t end=clock();
        printf("\nmxp=%d \n*/\n" ,mxp); 
        printf("order=O(n*n) NN=%d time=%.2f秒\n" ,NN,(double)(end-start)/CLOCKS_PER_SEC);
        }
        else
        {
            exit(0);
        }
    }
}
