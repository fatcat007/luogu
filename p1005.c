#include <stdio.h>
#include <string.h>

#define N 100

int a[80][80][N];
int f[80][80][N];
int s[N];


void input(int a[], int d)
{
	int i;
	for(i=0;d;i++)
	{
		a[i]=d%10;
		d/=10;
	}
}

void output(int a[])
{
	int i;
	int f=0;
	for(i=N-1;i>=0;i--)
	{
		if(a[i]) f=1;
		if(f)
			printf("%d",a[i]);
	}
	if(!f)
	{
		printf("0");
	}
}

void copy(int a[],int b[])
{
	int i;
	for(i=0;i<N;i++)
		a[i]=b[i];
}

int compare(int a[], int b[])
{
	int i;
	for(i=N-1;i>=0;i--)
		if(a[i]!=b[i])
			break;
	if(i>=0)
	{
		if(a[i]>b[i])
			return 1;
		else
			return -1;
	}

	return 0;
}


void add(int s[], int a[],int b[])
{
	int c=0;
	int i;
	for(i=0;i<N;i++)
	{
		s[i]=a[i]+b[i]+c;
		c=s[i]/10;
		s[i]%=10;
	}
}

int main()
{
	int n,m;
	int i,j,k;
	int d;

	scanf("%d %d",&n,&m);
	
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			//scanf("%lld", &a[i][j]);
			scanf("%d", &d);
			input(a[i][j],d);
		}
	//s=0;
	memset(s,0,sizeof(0));

	for(i=0;i<n;i++)
	{
		memset(f,0,sizeof(f));
		for(j=1;j<=m;j++)
			for(k=0;k<=m-j;k++)
			{
				//long long aa=f[j-1][k] + a[i][k+j-1]*(1<<(m-j+1));
				//long long bb=f[j-1][k+1] + a[i][k]*(1<<(m-j+1));
				//f[j][k] = aa>bb? aa:bb;
				//
				int aa[N];
				int bb[N];
				int t;
				copy(aa,a[i][k+j-1]);
				copy(bb,a[i][k]);
				for(t=0;t<m-j+1;t++)
				{
					add(aa, aa, aa); //aa=aa*2;
					add(bb, bb, bb); //bb=bb*2;
				}
				
				add(aa,aa,f[j-1][k]);
				add(bb,bb,f[j-1][k+1]);
				
				if(compare(aa,bb)>0)
					copy(f[j][k],aa);
				else
					copy(f[j][k],bb);
				if(i==0 && j==2 && k==0 && 0)	
				{
					printf("aa=");output(aa);printf("\r\n");
					printf("bb=");output(bb);printf("\r\n");
					printf("f=");output(f[j][k]);printf("\r\n");
				}
			}
		//s+=f[m][0];
		add(s,s,f[m][0]);
	}

	//printf("%lld",s);
	output(s);
	return 0;
}

