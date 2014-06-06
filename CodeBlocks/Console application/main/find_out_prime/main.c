#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,n;
    printf("You want to find the prime from 0 to :");
    scanf("%d",&n);
    for(b=2;b<n;b++)
    {
        for(a=2;b%a;a++);
        if(a==b)printf("%d\n",b);
    }
    return 0;
}
