#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int x,n=1;
    while(n=1)
    {
        printf("\n分解质因数(请勿输入变态大，小心烧电脑)\n");
        printf("输入合数：");
        scanf("%d",&x);
        while(n!=x)
        {
            x/=n;
            for(n=2;(x%n);n++);
            printf("    %d",n);
        }
    }
    return 0;
}
