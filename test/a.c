#include <stdio.h>
#include <string.h>
typedef struct Player
{
    char key[100][100];
	char value[100][100];
	int N,M;
	int num;
	char a[1000][1000];
}PL;

void play(PL* pl )
{
	int i,j,k;
	for(i=0;i<pl->N;i++)
		for(j=0;j<pl->num;j++)
			for(k=0;k<pl->M;k++)
			{
				if(!strcmp(pl->a[j],pl->key[k]))
				{	strcpy(pl->a[j],pl->value[k]);
					break;
				}			
			}
				
}

int main()
{
	int T;
	int i,j,t;
	
	char k;
	scanf("%d",&T);
	PL pl[T];
	for(t=0;t<T;t++)
	{
		scanf("%d%d",&pl[t].N,&pl[t].M);
		pl[t].N=pl[t].N-1;
	
	for(i=0;i<pl[t].M;i++)
	{
		scanf("%s",&pl[t].key[i]);
		scanf("%s",&pl[t].value[i]);
	}

	for(j=0;j<1000;j++)
		{
		if(scanf("%s",pl[t].a[j])==EOF)
			break;
		pl[t].num++;
		k=getchar();
		if(k=='\n')
			break;
		}
	}
	
	for(t=0;t<T;t++)
	{ 
		play(&pl[t]);
	} 
		
	for(t=0;t<T;t++)
	{
		for(i=0;i<pl[t].num;i++)
		{
			while(pl[t].a[i]=='\0')
				break;
			printf("%s ",pl[t].a[i]);
		}
		printf("\n");
	

	}	
}
