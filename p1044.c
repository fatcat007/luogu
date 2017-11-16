#include<stdio.h>
#include<string.h>

long long f[19];
int n;

int i,j;

int main()
{
	scanf("%d",&n);

	f[0]=1;

	for(i=1;i<=n;i++)
	{
		f[i]=0;
		for(j=0;j<=i-1;j++)
		{
			f[i]+=f[j]*f[i-1-j];
		}
	}
	printf("%lld",f[n]);
	return 0;
}

