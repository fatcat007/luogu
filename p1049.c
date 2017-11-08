#include<stdio.h>
#include<string.h>


int v;
int n;
int a[31];

int i,j;

int f[31][20001];

int main()
{
	scanf("%d",&v);
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);

	for(i=1;i<=n;i++)
		for(j=0;j<=v;j++)
			if(j>=a[i] && f[i-1][j-a[i]]+a[i]>f[i-1][j])
				f[i][j]=f[i-1][j-a[i]]+a[i];
			else
				f[i][j]=f[i-1][j];

	printf("%d", v-f[n][v]);
	return 0;
}

