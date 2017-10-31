#include <stdio.h>
#include <string.h>

int n=200;

void add(int a[], int b[])
{
	int i;
	int c=0;
	for(i=0;i<200;i++)
	{
		a[i]=a[i]+b[i]+c;
		c=a[i]/10;
		a[i]%=10;
	}
}

void multi(int a[], int b[])
{
	int i,j;
	int c=0;
	int s[400];
	memset(s,0,sizeof(s));

	for(i=0;i<200;i++)
		for(j=0;j<200;j++)
		{
			s[i+j]+=a[i]*b[j];
		}
	for(i=0;i<200;i++)
	{
		s[i]+=c;
		c=s[i]/10;
		s[i]%=10;
		a[i]=s[i];
	}
}

void print(int a[])
{
	int i;

	for(i=199;i>=0;i--)
		if(a[i]) break;

	if(i<0)
	{
		printf("0");
		return;
	}

	for(;i>=0;i--)
		printf("%d",a[i]);	
}

int main()
{
	int n;

	scanf("%d", &n);

	int i;

	int s[200];
	int m[200];
	int t[200];
	memset(s,0,sizeof(s));
	memset(m,0,sizeof(m));
	memset(t,0,sizeof(t));
	m[0]=1;
	for(i=1;i<=n;i++)
	{
		t[0]=i%10;
		t[1]=i/10;
		multi(m,t);
		add(s,m);
		//print(m);printf("\r\n");
	}
	print(s);
}

