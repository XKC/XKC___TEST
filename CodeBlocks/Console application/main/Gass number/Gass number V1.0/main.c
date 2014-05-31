#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER 100
#define WRONG_NUMBER 10

long sn=0;
clock_t time_start = 0;

void ING(void);
void CNN(void);
void RG(void);

int main()
{
    char command=0;

    printf("Guess the secret number between 1 and %d.\n\n",MAX_NUMBER);
    ING();
    do{
        CNN();
        printf("A new number has been chosen.\n");
        time_start = clock();
        RG();
        printf("Play again?(Y/N)");
        command='Y';
        do{
        scanf("%c",&command);
        }while(command==WRONG_NUMBER);
        printf("\n");
      }while(command=='y'||command=='Y');
    return 0;
}

void ING(void)
{
    srand((unsigned) time(NULL));
}

void CNN(void)
{
    sn = rand()%MAX_NUMBER+1;
}

void RG(void)
{
    int g , ng = 0;
    clock_t t= 0;
    static int best_ng = -5;
    static double best_time = -5;
    while(1)
{    ng++;
    printf("Enter guss:");
    scanf("%d",&g);
    if (g == sn){
        t = clock();
        printf("You won!\n  your record : in %d guesses               in %.2f S\n",ng,((t-time_start)/(double)CLOCKS_PER_SEC));
        if(ng<=best_ng||best_ng<0)best_ng=ng;
        if(((t-time_start)/(double)CLOCKS_PER_SEC)<=best_time||best_time<0)best_time=((clock()-time_start)/(double)CLOCKS_PER_SEC);
        printf("  Best record : in %d guesses               in %.2f S\n",best_ng,best_time);
        return;
        }else if (g<sn)
        printf("Too low\n");
        else
        printf("Too high\n");
}
}
