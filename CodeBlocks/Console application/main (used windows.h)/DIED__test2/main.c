#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{
    int i= 0;
    Sleep(3000);
    for(i=0;1;i++)
    {
        keybd_event(32,0,0,0);
        keybd_event(32,0,KEYEVENTF_KEYUP,0);
        keybd_event(13,0,0,0);
        keybd_event(13,0,KEYEVENTF_KEYUP,0);
        printf("%d\n",i);
    }
    return 0;
}
