
#include<stdio.h>
#include<string.h>

int d,r,n;
int nn[128];
int nl;
int i;

int main()
{
	scanf("%d %d", &d, &r);
	printf("%d=", d);
	while(d)
	{
		n=d%r;
		d/=r;

		if(n<0)
		{
			n-=r;
			d+=1;
		}
		nn[nl++]=n;
	}
	for(i=nl-1;i>=0;i--)
		if(nn[i]>=10)
			printf("%c",'A'+(nn[i]-10));
		else
			printf("%c",'0'+nn[i]);
	if(nl<=0)
		printf("0");
	printf("(base%d)",r);
	return 0;
}

