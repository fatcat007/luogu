#include<stdio.h>
#include<string.h>

int r;
char s[200];
int a[200];
int b[200];
int n;
int i,j;
int c;


int main()
{
	scanf("%d",&r);
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		if(r==16 && s[n-i-1]>='a' && s[n-i-1]<='f')
		{
			a[i]=(s[n-i-1]-'a')+10;
		}
		else if(r==16 && s[n-i-1]>='A' && s[n-i-1]<='F')
		{
			a[i]=(s[n-i-1]-'A')+10;
		}
		else
			a[i]=(s[n-i-1]-'0');

	}

	for(i=0;i<=30;i++)
	{
		for(j=0;j<n/2;j++)
		{
			if(a[j]!=a[n-j-1])
				break; /* not equal*/
		}
		if(j>=n/2) /* equal */
			break;

		for(j=0;j<n;j++)
			b[j]=a[j];
		c=0;
		for(j=0;j<n;j++)
		{
			a[j]+=b[n-j-1]+c;
			c=a[j]/r;
			a[j]%=r;
		}
		if(c)
		{
			a[n++]=c;
		}
		/*
		for(j=n-1;j>=0;j--)
			printf("%d ", a[j]);
		printf("\r\n");
		*/
	}

	if(i<=30)
		printf("STEP=%d",i);
	else
		printf("Impossible!");

		return 0;
}

