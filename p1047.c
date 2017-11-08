#include<stdio.h>
#include<string.h>

char f[100000];
int d;
int n;
int i;
int s,t;
int r;

int main()
{
	scanf("%d %d",&d,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&s,&t);
		memset(&f[s],1,t-s+1);
	}

	for(i=0;i<=d;i++)
		if(!f[i])
		r++;

	printf("%d",r);
	return 0;
}

