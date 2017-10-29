#include <stdio.h>

int n;
int a[10][10];
int f[19][11][11];
int i,j,k,l;
int d[4][2] = { {0,0}, {0,-1},{-1,-1},{-1,0}};

int main()
{
	scanf("%d", &n);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d", &a[i][j]);

	memset(f,0,sizeof(f));

	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			for(k=1;k<=i;k++)
			{
				int max=0;
				for(l=0;l<4;l++)
				{
					int m=j+d[l][0];
					int n=k+d[l][1];
					if(f[i-1][m][n]>max)
						max=f[i-1][m][n];
				}

				int t=a[i-j+1][j];
				if(j!=k)
					t+=a[i-k+1][k];

				f[i][j][k]=max+t;
			}

	for(i=n+1;i<=2*n+1;i++)
		for(j=i-n;j<=n+1;j++)
			for(k=i-n;k<=n+1;k++)
			{
				int max=0;
				for(l=0;l<4;l++)
				{
					int m=j+d[l][0];
					int n=k+d[l][1];
					if(f[i-1][m][n]>max)
						max=f[i-1][m][n];
				}

				int t=a[n-j+1][i-n+j-1];//i=n+1, j=1, get a[n][1]
				if(j!=k)
					t+=a[n-k+1][i-n+k-1];//i=n+1, k=1, get a[n][1]
				f[i][j][k]=max+t;
			}

	//for(i=1;i<=2*n+1;i++)
	//	if(n%2)
	//		printf("f[%d]=%d\r\n", i, f[i][i/2+1][i/2+1]); //i=1, f[1][1][1]; i=3, f[3][2][2]
	printf("%d", f[2*n+1][n+1][n+1]);

	return 0;
}

