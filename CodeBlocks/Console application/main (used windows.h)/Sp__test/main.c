#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void ING(void);
int main()
{
    int i,a,b,L,I,C,n = 0;
    ING();
    printf("number:");
    scanf("%d",&n);
    printf("From:");
    scanf("%d",&a);
    printf("  to:");
    scanf("%d",&b);
    printf("\n move in 3s");
    Sleep(3000);
    for(i=0;i<=n;i++)
    {
        L=rand()%(b-a+1)+a;
        for(I=0;I<L;I++)
        {
            C=rand()%26+65;
            keybd_event(C,0,0,0);
            keybd_event(C,0,KEYEVENTF_KEYUP,0);
        }
        keybd_event(32,0,0,0);
        keybd_event(32,0,KEYEVENTF_KEYUP,0);
        keybd_event(13,0,0,0);
        keybd_event(13,0,KEYEVENTF_KEYUP,0);
        keybd_event(0x11,0,0,0);
        keybd_event(0x0D,0,0,0);
        keybd_event(0x0D,0,KEYEVENTF_KEYUP,0);
        keybd_event(0x11,0,KEYEVENTF_KEYUP,0);
        Sleep(2);
        printf("%d\n",i);
    }
    return 0;
}

void ING(void)
{
    srand((unsigned) time(NULL));
}
