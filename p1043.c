#include<stdio.h>
#include<string.h>

int a[51];
int aa[51][51];
int f[51][51][10];
int g[51][51][10];

int n;
int m;

int i,j,k,p;
int min,max;

int main()
{
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(j=0;j<=n;j++)
		for(i=0;i<n;i++)
		{
			if(j==0)
			{
				aa[i][j]=0;
				continue;
			}
			aa[i][j]=(a[i]+aa[(i+1)%n][j-1])%10;
			if(aa[i][j]<0) aa[i][j]+=10;
		}


	for(k=1;k<=m;k++)
		for(j=k;j<=n;j++)
			for(i=0;i<n;i++)
			{
				if(k==1)
				{
					f[i][j][k]=aa[i][j];
					g[i][j][k]=aa[i][j];
					continue;
				}

				f[i][j][k]=-1;
				for(p=1;p<=j;p++)
				{
					if(j-p<k-1) break;

					if(f[i][j][k]<0 || aa[i][p]*f[(i+p)%n][j-p][k-1]<f[i][j][k])
						f[i][j][k]=aa[i][p]*f[(i+p)%n][j-p][k-1];	
				}
				g[i][j][k]=-1;
				for(p=1;p<=j;p++)
				{
					if(j-p<k-1) break;
					if(g[i][j][k]<0 || aa[i][p]*g[(i+p)%n][j-p][k-1]>g[i][j][k])
						g[i][j][k]=aa[i][p]*g[(i+p)%n][j-p][k-1];
				}
			//	if(k==2) printf("g[%d][%d][%d]=%d\r\n",i,j,k,g[i][j][k]);
			}

	min=-1;
	max=-1;
	for(i=0;i<n;i++)
	{
		if(min<0 || f[i][n][m]<min)
			min=f[i][n][m];
		if(max<0 || g[i][n][m]>max)
			max=g[i][n][m];
	}

	printf("%d\r\n%d\r\n", min,max);
	return 0;
}

