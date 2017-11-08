#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int n;
	int sn;
	int a;
	int sa;
	scanf("%d",&n);

	a=sqrt(2*n);
	while(a*a+a<2*n)
		a++;

	n-=a*(a-1)/2;

	//printf("a=%d,n=%d\r\n", a, n);

	if(a%2)
	{
		printf("%d/%d",a+1-n,n);
	}else
	{
		printf("%d/%d",n,a+1-n);
	}
	return 0;
}
