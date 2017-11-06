#include<stdio.h>
#include<string.h>

int n;
int a[128];
int s[128][128];
int f[128][128];
int g[128][128];
int i,j,k;

int max;
int min;

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(j=1;j<=n;j++)
		for(i=0;i<n;i++)
			s[i][j]=a[i]+s[(i+1)%n][j-1];

	for(j=2;j<=n;j++)
		for(i=0;i<n;i++)
		{
			max=0;
			min=-1;
			for(k=1;k<=j-1;k++)
			{
				if(f[i][k]+f[(i+k)%n][j-k]+s[i][j] > max)
					max=f[i][k]+f[(i+k)%n][j-k]+s[i][j];
				if(min<0 || g[i][k]+g[(i+k)%n][j-k]+s[i][j] < min)
					min=g[i][k]+g[(i+k)%n][j-k]+s[i][j];
			}
			f[i][j]=max;
			g[i][j]=min;
		}

	max=0;
	min=-1;
	for(i=0;i<n;i++)
	{
		if(f[i][n]>max)
			max=f[i][n];
		if(min<0 || g[i][n]<min)
			min=g[i][n];
	}
	printf("%d\r\n",min);
	printf("%d\r\n",max);
	return 0;
}

