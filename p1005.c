#include <stdio.h>
#include <string.h>

#define N 60

typedef unsigned long u32;
typedef unsigned long long u64;

int div(u32 v[], u32* pr, u32 n[], u32 d)
{
	u64 carry=0;
	u64 t;
	int i;
	int ret=0;

	for(i=N-1;i>=0;i--)
	{
		t= (carry<<32) | n[i];
		v[i]=t/d;
		carry=t%d;
		if(v[i]) ret=1;
	}
	*pr=(u32)carry;

	return ret;
}

u32 pt[N];
char ps[1024];

void print(u32 n[])
{
	int i;
	u32 r;

	for(i=0;i<N;i++)
		pt[i]=n[i];

	i=0;
	while(1)
	{
		int ret=div(pt, &r, pt, 10);
		ps[i++]='0'+r;
		if(!ret) break;
	}

	if(!i)
	{
		printf("0");
		return;
	}

	for(i--;i>=0;i--)
	{
		printf("%c", ps[i]);
	}
}


void copy(u32 a[],u32 b[])
{
	int i;
	for(i=0;i<N;i++)
		a[i]=b[i];
}

int compare(u32 a[], u32 b[])
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

void add(u32 s[], u32 a[],u32 b[])
{
	int i;
	u32 c;
	for(i=0,c=0;i<N;i++)
	{
		u64 t=(u64)a[i]+(u64)b[i]+(u64)c;
		c=(u32)(t>>32);
		s[i]=(u32)t;
	}
}

void shift(u32 a[], int n)
{
	int off=n/32;
	int shft=n%32;
	int i;

	for(i=N-1;i>=off;i--)
	{
		a[i] =(a[i-off]<<shft); //shift bits
		if(i>=off+1 && shft)
			a[i] |=(a[i-off-1]>>(32-shft)); //add tail bits
	}
	for(;i>=0;i--)
		a[i]=0;
}

u32 a[80][80][N];
u32 f[80][80][N];
u32 s[N];


int main()
{
	int n,m;
	int i,j,k;
	scanf("%d %d",&n,&m);
	
	memset(a,0,sizeof(a));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			//scanf("%lld", &a[i][j]);
			scanf("%d", &a[i][j][0]);
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
				u32 aa[N];
				u32 bb[N];
				
				copy(aa,a[i][k+j-1]);
				shift(aa,m-j+1);

				copy(bb,a[i][k]);
				shift(bb,m-j+1);

				add(aa,aa,f[j-1][k]);
				add(bb,bb,f[j-1][k+1]);
				
				if(compare(aa,bb)>0)
					copy(f[j][k],aa);
				else
					copy(f[j][k],bb);
				if(i==0 && j==2 && k==0 && 0)	
				{
					printf("aa=");print(aa);printf("\r\n");
					printf("bb=");print(bb);printf("\r\n");
					printf("f=");print(f[j][k]);printf("\r\n");
				}
			}
		//s+=f[m][0];
		add(s,s,f[m][0]);
	}

	//printf("%lld",s);
	print(s);
	return 0;
}

