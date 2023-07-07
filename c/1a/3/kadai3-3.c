#include <stdio.h>
#define Ni 3
#define Nj 4
int A[Nj]={11,12,13,14};
int B[Ni][Nj]={1,2,3,4,11,12,13,14,21,22,23,24};

int main(void)
{
    printf("/**P3-3(配列とpointer)  **\n");
    printf("step1:\n");
    for(int j=0; j<Nj; j++) printf("A[%d]=%2d",j,A[j]);

    printf("\n\nstep2:(アドレスのつながりを確認しよう)\n");
    printf("A=%p",A);
    for(int j=0; j<Nj; j++) printf("&A[%d]=%p",j,&A[j]);

    printf("\nstep3\n");
    for(int i=0; i<Ni; i++)
    {
        for(int j=0; j<Nj; j++)
            printf("B[%d][%d]=%2d",i,j,&B[i][j]);
        printf("\n");
    }

    printf("\nstep4:(アドレスのつながりを確認しよう)\n");
    printf("B=%p B[0]=%p B[1]=%p B[2]=%p\n",B,B[0],B[1],B[2]);
    for(int i=0; i<Ni; i++)
    {
        for(int j=0; j<Nj; j++)
            printf("&B[%d][%d]=%p",i,j,&B[i][j]);
        printf("\n");
    }

    printf("step5:\n");
    int C[Nj];
    for(int j=0; j<Nj; j++) C[j]=B[2][j]+100;
    for(int j=0; j<Nj; j++) printf("C[%d]=%3d",j,C[j]);
    printf("\n*/\n");
}
