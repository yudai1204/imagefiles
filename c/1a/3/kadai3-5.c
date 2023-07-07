#include <stdio.h>
#include <stdlib.h>
union InFloat
{
    int ival;
    float fval;
};

int main()
{
    float f[4] = {0.5, 0.75, 0.875, 99.9};
    printf("f0=%f\n", f[0]);
    union InFloat target;
    for (int i = 0; i < 4; i++)
    {
        target.fval = f[i];
        printf("f[%d]=%f", i, f[i]);
        for (int k = 0; k < 32; k++)
        {
            if (target.ival < 0)
                printf("1");
            else
                printf("0");
            target.ival = target.ival << 1;
        }
        printf("\n");
    }
    return 0;
}
