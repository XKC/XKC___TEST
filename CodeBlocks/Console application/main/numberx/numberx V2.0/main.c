#include <stdio.h>
#include <stdlib.h>

int main()
{
    long int x,n=1;
    while(n=1)
    {
        printf("\n�ֽ�������(���������̬��С���յ���)\n");
        printf("���������");
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
