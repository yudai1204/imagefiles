#include <stdio.h>
#define N 100
int main()
{
    int array[N];
    for (int m = 0;; m++)
    {
        int size;
        printf("enter Size =");
        scanf("%d", &size);
        if (size == 0)
            return 1;
        printf("Output:\n");
        for (int k = 0;; k++)
        {
            if (k == size)
                break;
            if(!(k%2))
                array[k]=-1;
            else
                array[k] = k;
        }
        printf("array[]={");
        for (int i = 0; i < size; i++)
            printf("%4d", array[i]);
        printf(" }\n");
    }
    return 0;
}