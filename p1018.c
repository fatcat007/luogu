#include<stdio.h>
#include<string.h>

int n,k;
char s[64];

long long f[41][7];

int i,j,t;

int main()
{
	scanf("%d %d",&n,&k);
	scanf("%s",s);
	for(i=1;i<=n;i++) /* string long i*/
		for(j=1;j<=k+1;j++) /* div into j part*/
		{
			long long base=1;
			long long sum=0;
			long long max=0;
			if(j>i) /* can't div*/
				break;

			for(t=i-1;t>=0;t--) /* t long string div into j-1 part*/
			{
				if(j-1>t)
					break; /* cat't div string t into j part*/

				sum+=base*(long long)(s[t]-'0');
				base*=10;

				if(sum+f[t][j-1] > max)
					max=sum+f[t][j-1];
			}
			f[i][j]=max;
		}

	printf("%lld",f[n][k+1]);
	return 0;

}

