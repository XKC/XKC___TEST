#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define N 2               //<=10
#define WINNUMBER 5     //2^WINNUMBER
#define NEWNUMBERPER 1   //make NEWNUMBERPER per

int Array_2048 [N][N] = {0};
char name [11] = {'\0'};
long highest_score[11][2] = {0};
char highest_name[11][11] = {"?","?","?","?","?","?","?","?","?","?","?"};

int your_NO = 0;
long score = 0;
long highest_number = 0;
int win_number = WINNUMBER;

void ING(void);
int read_line (char str[],int n);
void Prinft_Array_2048(void);
int Make_new_number(int n);
int GO_up(void);
int GO_down(void);
int GO_left(void);
int GO_right(void);
int test_highest(void);
void prinft_scoretable(void);
void Make_scoretable(void);
int read(void);
int IS_died(void);


int main()
{
    char command = 0;
    int Enter = 0;
    int Keep_go = 1;
    long Highest_score = 0;                                                                           //记录最高得分
    int i = 0;                                                                                        //用于清零
    int a = 0;                                                                                        //用于清零
    int b = 0;                                                                                        //用于清零

    ING();                                                                                            //重置随机数

    do{
        {                                                                                             //对不需保存的变量进行清零
        system("cls");
        system("COLOR 8F");
        score = your_NO = 0;
        Keep_go = 1;
        win_number = WINNUMBER;
        for(i=0;i<11;i++)
            name[i] = '\0';
        for(a = 0;a < N ; a++)
            for(b = 0;b < N ; b++)
                Array_2048[a][b] = 0;
        }
        {                                                                                             //打印欢迎语
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf( " Welcome to 2048! Your mission is to get the number %d!\n",(1<<win_number));
        printf( " Please enter your name: ");
        }
        read_line(name,10);                                                                           //读入用户的姓名
        Make_new_number(NEWNUMBERPER);                                                                //生成第一个随机数
        do{                                                                                           //正常游戏
            {                                                                                         //打印 欢迎语&数表
            system("cls");
            system("COLOR 8A");
            printf("*******************************************************************************\n\n");
            printf("*******************************************************************************\n\n");
            printf("*******************************************************************************\n\n");
            printf( " Hi, %3s!Welcome to 2048! Your mission is to get the number %d!\n",name,(1<<win_number));
            Prinft_Array_2048();
            }
            {                                                                                         //打印 提示语&最高记录与分数
            printf("Enter what you want to: \n( 5:display score rank/2:go down/4:go left/6:go right/8:go up \n)");
            printf("The highest score: %6ld         Your score: %2ld\n",Highest_score,score);
            }
            Enter = read();
            {                                                                                         //判断位移反向，位移，判断位移是否成功（失败要求重来）
            if(Enter == 2) {if(GO_down()!=1) continue;}
            else if(Enter == 4) {if(GO_left()!=1) continue;}
            else if(Enter == 6) {if(GO_right()!=1) continue;}
            else if(Enter == 8) {if(GO_up()!=1) continue;}
            else if(Enter == 5)
                                {
                                    prinft_scoretable();
                                    printf("Press any key to keep going\n");
                                    scanf("%c",&a);
                                    continue;
                                }
            else    continue;
            }

            if(score>=Highest_score)Highest_score=score;                                              //刷新最高分
            Make_scoretable();                                                                        //刷新排行榜
            if((highest_number=test_highest())>=win_number)                                           //是否赢了，询问是否继续
            {
                win_number++;
                Prinft_Array_2048();
                printf("Keep going?(Y/N)");
                do{                                                                                   //去抖
                    scanf("%c",&command);
                }while(command=='\n');
                printf("\n");
                if(command=='n'||command=='N')break;
            }
            Keep_go = Make_new_number(NEWNUMBERPER);                                                  //生成新的随机数，同时将是否生成成功记录在 Keep_go 中
            if(IS_died()) break;                                                                      //死局判断，是死局及跳出
        }while(Keep_go);                                                                              //生成新的随机数失败跳出
        {                                                                                             //Game Over（死局、空位不足）后 显示最高分，你的成绩，结束时你的情况与积分表
        system("cls");
        system("COLOR 8C");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("*******************************************************************************\n\n");
        printf("The highest score: %6ld",Highest_score);
        printf("Your score: %2ld\n",score);
        Prinft_Array_2048();
        printf(" Game over!\n\n");
        prinft_scoretable();
        printf("Play again?(Y/N)");
        }
        do{                                                                                           //去抖
            scanf("%c",&command);
        }while(command=='\n');
        printf("\n");
      }while(command=='y'||command=='Y');                                                             //是否重来
    return 0;
}


void ING(void)                                                                                        //重置随机数（设置种子）
{
    srand((unsigned) time(NULL));
}

int read_line (char str[],int n)
{
    int ch , i = 0;
    while((ch = getchar())==' '||ch=='\n'||ch=='\0');
    while(ch!='\n')
    {
        if(i<n)
           str[i++] = ch;
        ch = getchar();
    }
    str[i]='\0';
    return i;
}

void Prinft_Array_2048(void)
{
    int i = 0;int I = 0;
    printf("*");
    for(I = 0;I < N+1 ; I++)printf("      *");
    printf("\n\n\n");
    for(i = 0;i < N ; i++)
    {
        printf("*");
        for(I = 0;I < N ; I++)
            if(Array_2048[i][I]==0)printf("       ");
            else printf("  %5d",Array_2048[i][I]);
        printf("      *");
        printf("\n\n\n");
    }
    printf("*");
    for(I = 0;I < N+1 ; I++)printf("      *");
    printf("\n\n\n");
}

int Make_new_number(int n)
{
    int L = 0;
    for(L = 0; L < n ; L++)
    {
        int a = 0;int b = 0;int i = 0;long empty = 0;long R_NO = 0;
        for(a = 0;a < N ; a++)
            for(b = 0;b < N ; b++)
                empty += !(Array_2048[a][b]);
        if(empty == 0) return 0;
        R_NO = rand()%empty+1;
        a = b = i = 0;
        while(1)
        {
            i += !(Array_2048[a][b]);
            if(i>=R_NO) break;
            b++;
            if(b>=N)
            {
                a++;
                b=0;
            }
        }
        Array_2048[a][b] = 2 << ((rand()%4)/3);
    }
    return 1;
}

int GO_up(void)
{
    int a = 0;int b = 0;int Ln = 0;int NO_n = 0;int NLn = 0;int L =0;
    for(b = 0;b < N ; b++)
    {
        for(a = Ln = NO_n = NLn = 0;a < N ; a++)
        {
            if(Array_2048[a][b]!=0)
            {
                if(Array_2048[a][b]==Ln)
                {
                    Array_2048[NLn][b]=Array_2048[NLn][b]<<1;
                    score += Array_2048[a][NLn];
                    NLn = NO_n;
                    Ln = 0;
                    Array_2048[a][b]=0;
                    L=1;
                }
                else
                {
                    Array_2048[NO_n][b] = Array_2048[a][b];
                    Ln= Array_2048[a][b];
                    if(NO_n!=a)
                    {
                        Array_2048[a][b]=0;
                        L=1;
                    }
                    NLn = NO_n;
                    NO_n++;
                }
            }
        }
    }
    return L;
}

int GO_down(void)
{
    int a = 0;int b = 0;int Ln = 0;int NO_n = 0;int NLn = 0;int L =0;
    for(b = 0;b < N ; b++)
    {
        for(a = NO_n = NLn =N-1, Ln = 0;a >= 0 ; a--)
        {
            if(Array_2048[a][b]!=0)
            {
                if(Array_2048[a][b]==Ln)
                {
                    Array_2048[NLn][b]=Array_2048[NLn][b]<<1;
                    score += Array_2048[a][NLn];
                    NLn = NO_n;
                    Ln = 0;
                    Array_2048[a][b]=0;
                    L=1;
                }
                else
                {
                    Array_2048[NO_n][b] = Array_2048[a][b];
                    Ln= Array_2048[a][b];
                    if(NO_n!=a)
                    {
                        Array_2048[a][b]=0;
                        L=1;
                    }
                    NLn = NO_n;
                    NO_n--;
                }
            }
        }
    }
    return L;
}

int GO_left(void)
{
    int a = 0;int b = 0;int Ln = 0;int NO_n = 0;int NLn = 0;int L =0;
    for(a = 0;a < N ; a++)
    {
        for(b = Ln = NO_n = NLn = 0;b < N ; b++)
        {
            if(Array_2048[a][b]!=0)
            {
                if(Array_2048[a][b]==Ln)
                {
                    Array_2048[a][NLn]=Array_2048[a][NLn]<<1;
                    score += Array_2048[a][NLn];
                    NLn = NO_n;
                    Ln = 0;
                    Array_2048[a][b]=0;
                    L=1;
                }
                else
                {
                    Array_2048[a][NO_n] = Array_2048[a][b];
                    Ln= Array_2048[a][b];
                    if(NO_n!=b)
                    {
                        Array_2048[a][b]=0;
                        L=1;
                    }
                    NLn = NO_n;
                    NO_n++;
                }
            }
        }
    }
    return L;
}

int GO_right(void)
{
    int a = 0;int b = 0;int Ln = 0;int NO_n = 0;int NLn = 0;int L =0;
    for(a = 0;a < N ; a++)
    {
        for(b = NO_n = NLn = N-1,Ln = 0;b >= 0 ; b--)
        {
            if(Array_2048[a][b]!=0)
            {
                if(Array_2048[a][b]==Ln)
                {
                    Array_2048[a][NLn]=Array_2048[a][NLn]<<1;
                    score += Array_2048[a][NLn];
                    NLn = NO_n;
                    Ln = 0;
                    Array_2048[a][b]=0;
                    L=1;
                }
                else
                {
                    Array_2048[a][NO_n] = Array_2048[a][b];
                    Ln= Array_2048[a][b];
                    if(NO_n!=b)
                    {
                        Array_2048[a][b]=0;
                        L=1;
                    }
                    NLn = NO_n;
                    NO_n--;
                }
            }
        }
    }
    return L;
}

int test_highest(void)
{
        int a = 0;int b = 0;int i = 0;long highest = 0;
        for(a = 0;a < N ; a++)
        {
            for(b = 0;b < N ; b++)
                if((Array_2048[a][b])>=highest) highest=Array_2048[a][b];
        }
        for(i=0;highest>1;i++)
            highest=highest>>1;
        return i;
}

void prinft_scoretable(void)
{
    int i = 0;char L [11]={'\0'};
    for (i=10;i>0;i--)
    {
        strcpy(L,highest_name[i]);
        printf("  %2d    %10s   %6ld",(11-i),L,(highest_score[i][0]));
        if(highest_score[i][1]!=0) printf("   %6d",(1<<(highest_score[i][1])));
        else printf("        0");
        if(i==your_NO)printf("   ***");
        printf("\n");
    }
}

void Make_scoretable(void)
{
    int i = 0; long I = 0; char L [11]={0};
    highest_score[your_NO][0]=score;
    highest_score[your_NO][1]=highest_number;
    for(i=0;i<11;i++)
        highest_name[your_NO][i]=name[i];
    while(your_NO<10)
    {
        if((highest_score[your_NO][1]>highest_score[(your_NO+1)][1])||((highest_score[your_NO][1]==highest_score[(your_NO+1)][1])&&(highest_score[your_NO][0]>=highest_score[(your_NO+1)][0])))
        {
            I = highest_score[(your_NO+1)][1];
            highest_score[(your_NO+1)][1] = highest_score[your_NO][1];
            highest_score[your_NO][1] = I;
            I = highest_score[(your_NO+1)][0];
            highest_score[(your_NO+1)][0] = highest_score[your_NO][0];
            highest_score[your_NO][0] = I;
            strcpy(L,highest_name[your_NO+1]);
            strcpy(highest_name[your_NO+1],highest_name[your_NO]);
            strcpy(highest_name[your_NO],L);
            your_NO++;
        }
        else
            break;
    }
}

int read(void)
{
    char a = 0;char c =0;
    while(1)
    {
        a = c = 0;
        do{
            scanf("%c",&a);
        }while(a=='\n');
        scanf("%c",&c);
        if(c=='\n')
        {
            if(a=='w'||a=='W'||a=='8')return 8;
            if(a=='a'||a=='A'||a=='4')return 4;
            if(a=='s'||a=='S'||a=='2')return 2;
            if(a=='d'||a=='D'||a=='6')return 6;
            if(a=='m'||a=='M'||a=='5')return 5;
        }
    }
}

int IS_died(void)
{
    int a = 0;int b = 0;int i = 0;

    for(a = 0;a < N ; a++)
    {
        for(b = 0;b < N ; b++)
        {
            if(Array_2048[a][b]==0)
            {
                return 0;
            }
        }
    }
    for(b = 0;b < N ; b++)
    {
        for(a = i = 0;a < N ; a++)
        {
            if(Array_2048[a][b]==i)
            {
                return 0;
            }
            else
            {
                i = Array_2048[a][b];
            }
        }
    }
    for(a = 0;a < N ; a++)
    {
        for(b = i = 0;b < N ; b++)
            {
                if(Array_2048[a][b]==i)
                {
                    return 0;
                }
                else
                {
                    i = Array_2048[a][b];
                }
            }
    }
    return 1;
}
