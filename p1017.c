
#include<stdlib.h>
#include<string.h>


int main()
{
	int d,r;
	scanf("%d %d", &d, &r);

	int p,b,n;

	if(d>=0)
	{
		p=0;
		b=1;
		while(b<d)
		{
			b*=(r*r);
			p+=2;
		}
	}
	else
	{
		p=1;
		b=r;
		while(b>d)
		{
			b*=(r*r);
			p+=2;
		}
	}

	while(p>=0)
	{
		n=d/(b/(r*r));

		if(n>=10)
			printf("%c",'A'+n);
		else
			printf("%c",n)
		d=d-b;
		b/=r;
		p--;
	}
	return 0;
}

