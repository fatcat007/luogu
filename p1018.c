#include<stdio.h>
#include<string.h>

typedef unsigned long u32;
typedef unsigned long long u64;

#define N 6
#define R 1000000000
#define L 9

u64 t[2*N];
u64 c;
void add(u32 r[],u32 a[],u32 b[])
{
	int i;

	memset(t,0,sizeof(t));

	for(i=0;i<N;i++)
		t[i]=(u64)a[i]+(u64)b[i];

	c=0;
	for(i=0;i<N;i++)
	{
		c+=t[i];
		r[i]=(u32)(c%R);
		c/=R;
	}
}

void multi(u32 r[],u32 a[], u32 b[])
{
	int i,j;

	memset(t,0,sizeof(t));

	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			t[i+j]+=(u64)a[i]*(u64)b[j];

	c=0;
	for(i=0;i<N;i++)
	{
		c+=t[i];
		r[i]=(u32)(c%R);
		c/=R;
	}
}

void copy(u32 a[],u32 b[])
{
	int i;
	for(i=0;i<N;i++)
		a[i]=b[i];
}

int compare(u32 a[],u32 b[])
{
	int i;
	for(i=N-1;i>=0;i--)
		if(a[i]!=b[i])
			break;

	if(i<0)
		return 0;

	if(a[i]>b[i])
		return 1;
	else
		return -1;
}

void input(u32 a[], char s[], int sl)
{
	int i,j;

	u32 base;

	for(i=0;i<N;i++)
	{
		a[i]=0;
		base=1;
		for(j=0;j<L;j++)
		{
			if(!sl) break;

			a[i]+=base*(s[sl-1]-'0');
			base*=10;
			sl--;
		}
	}
}

void output(u32 a[])
{
	int i;
	int f=0;
	for(i=N-1;i>=0;i--)
	{
		if(f)
		{
			printf("%09d",a[i]);
		}
		else if(a[i])
		{
			printf("%d",a[i]);
			f=1;
		}
	}

	if(!f)
		printf("0");
}

int n,k;
char s[64];

u32 f[41][7][N];

int i,j,p;

int main()
{
        scanf("%d %d",&n,&k);
        scanf("%s",s);

        for(i=0;i<=n;i++) /* string long i*/
                for(j=0;j<=k+1;j++) /* div into j part*/
                {
			if(i==0 || j==0)
			{
				f[i][j][0]=1;
				continue;
			}
                        if(j>i) /* can't div*/
                                break;

			u32 max[N];
			memset(max,0,sizeof(max));

                        for(p=i-1;p>=0;p--) /* t long string div into j-1 part*/
                        {
                                if(j-1>p)
                                        break; /* cat't div string t into j part*/

				u32 m[N];
				u32 r[N];
				input(m,&s[p],i-p);
				multi(r,f[p][j-1],m);
                                if(compare(r, max)>0)
                                        copy(max,r);
                        }
                        copy(f[i][j],max);
                }

        output(f[n][k+1]);

	return 0;
}

