#include<stdio.h>
#include<string.h>

int a[101];
int n;
int i;
int p;
int r;

int main()
{
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}

	p=a[n]/n;

	for(i=1;i<=n;i++)
	{
		if(a[i]!=p*i)
			r++;
	}
	printf("%d",r);
	return 0;
}

