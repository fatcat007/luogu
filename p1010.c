#include<stdio.h>
#include<string.h>


void print(unsigned int n)
{
	int i;
	int f;

	if(n<=2)
	{
		printf("%d",n);
		return;
	}

	i=31;
	f=0;
	while(n)
	{
		if(n&0x80000000)
		{
			if(f) printf("+");
			printf("2");
			if(i!=1)
			{
				printf("(");
				print(i);
				printf(")");
			}
			f=1;
		}
		n<<=1;
		i--;
	}
}

int main()
{
	int n;
	scanf("%d",&n);

	print(n);
	return 0;
}

