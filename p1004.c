#include <stdio.h>
#include <string.h>

int n;
int a[10][10];
int f[19][11][11];
int i,j,k,x,y;
int d[2][2] = { {-1,0}, {0,-1}};

int main()
{
	memset(a,0,sizeof(a));
	memset(f,0,sizeof(f));
	
	scanf("%d", &n);
	
	for(;;){
		scanf("%d %d %d", &j,&k,&x);
		if(!x&&!y&&!x) break;
		a[j][k]=x;
	}

	for(i=1;i<=2*n-1;i++)
	{
		int p,q;
		if(i<=n)
		{
			p=i;
			q=1;
		}
		else
		{
			p=n;
			q=i-n+1;
		}

		for(j=p,k=q;j>=1 && j<=n && k>=1 && k<=n;j--,k++)
		{
			for(x=p,y=q;x>=1 && x<=n && y>=1 && y<=n;x--,y++)
			{
				int max=0;
				int l,t;
				for(l=0;l<2;l++)
				{
					int jj=j+d[l][0];
					int kk=k+d[l][1];
					for(t=0;t<2;t++)
					{
						int xx=x+d[t][0];
						int yy=y+d[t][1];

						if(f[i-1][jj][xx]>max)
							max=f[i-1][jj][xx];
					}
				}
				int num=a[j][k];
				if(x!=j)
					num+=a[x][y];

				f[i][j][x]=max+num;

			}
		}
	}	

	printf("%d", f[2*n-1][n][n]);

	return 0;
}

