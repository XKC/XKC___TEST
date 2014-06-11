#include <stdio.h>

void input(char [][21],int,int);
void output(char [][21],int);
int trans(char [][21],int,int);

int main()
{
	int row,col,ret,i;
	char tab[20][21];

	for(;;)
	{
		printf("输入行数和列数(行,列):");
		ret=scanf("%d,%d",&row,&col);
		if(ret==2 && (9<=row && row<=20) && (9<=col && col<=20))
			break;
		else
			printf("输入错误!请重新输入!\n");
		fflush(stdin);
	}
	input(tab,row,col);
	for(i=0;i<10;i++)
	{
		if(trans(tab,row,col))
			output(tab,row);
		else
			break;
	}
	return 0;
}

void input(char tab[][21],int row,int col)
{
	int i,j,c;

	for(c=0;c!=col;)
	{
		printf("输入列表:\n");
		for(i=0;i<row;i++)
		{
			scanf("%s",tab[i]);
			for(c=j=0;tab[i][j];j++)
			{
				if(tab[i][j]=='*' || tab[i][j]=='.')
					c++;
				else
					break;
			}
			if(c!=col)
			{
				printf("输入错误!请重新输入!\n");
				break;
			}
		}
		fflush(stdin);
	}
}

void output(char tab[][21],int row)
{
	int i;

	printf("输出列表:\n");
	for(i=0;i<row;i++)
		printf("%s\n",tab[i]);
}

int trans(char tab[][21],int row,int col)
{
	int i,j,x,y,c,change=0;
	char t[20][20];

	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			for(c=0,x=i-1;x<=i+1;x++)
			{
				if(x<0 || x>=row)
					continue;
				for(y=j-1;y<=j+1;y++)
				{
					if(y<0 || y>=col || (x==i && y==j))
						continue;
					if(tab[x][y]=='*')
						c++;
				}
			}
			t[i][j]=(c==3 || tab[i][j]=='*' && c==2)?'*':'.';
			if(tab[i][j]!=t[i][j])
				change=1;
		}
	}
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			tab[i][j]=t[i][j];
	return change;
}
