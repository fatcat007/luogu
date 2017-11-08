#include<stdio.h>
#include<string.h>

int d,n;
int t[101];
int v[101]; 

int i,j,k;

int f[101][1001];

int main()
{
	scanf("%d %d",&d,&n);
	for(i=1;i<=n;i++)
		scanf("%d %d",&t[i],&v[i]);


	for(i=1;i<=n;i++)
		for(j=0;j<=d;j++)
		{
			if(j>=t[i] && f[i-1][j-t[i]]+v[i]>f[i-1][j])
				f[i][j]=f[i-1][j-t[i]]+v[i];
			else
				f[i][j]=f[i-1][j];
		}

	printf("%d",f[n][d]);

	return 0;
}

