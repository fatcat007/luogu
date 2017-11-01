#include<stdio.h>
#include<string.h>

int a[51][51];
int f[101][51][51];
int d[2][2] = {{0,-1},{-1,0}};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);

	int i,j,jj,k,kk;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);

	for(i=1;i<m+n;i++)
	{
		for(j=1,jj=i;jj>=1;j++,jj--)
		{
			if(j<1 || j>n || jj<1 || jj>m) /* out of range*/
				continue;

			for(k=1,kk=i;kk>=1;k++,kk--)
			{
				if(k<1 || k>n || kk<1 || kk>m) /* out of range*/
					continue;

				if(j==k && j!=n)
					continue; /* to same position is not allow, execpt (n,m) */

				int max=0;
				int p,q;
				for(p=0;p<2;p++)
				{
					int x,y;
					x=j+d[p][0];
					y=jj+d[p][1];
					for(q=0;q<2;q++)
					{
						int xx,yy;
						xx=k+d[q][0];
						yy=kk+d[q][1];

						if(x==xx && x!=1)
							continue; /* from same position is not allow, execpt (1,1)*/

						if(f[i-1][x][xx]>max)
							max=f[i-1][x][xx];
					}
				}
				f[i][j][k]=max+a[j][jj]+a[k][kk];
			}
		}
	}

	printf("%d", f[n+m-1][n][n]);
	return 0;
}

