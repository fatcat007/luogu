#include<stdio.h>
#include<string.h>

int main()
{
	int l;
	int n;
	int s;
	int i;
	int min=0,max=0; /* max(per min), max(per max) */
	
	scanf("%d",&l);
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&s);
		if(s<=(l+1)/2) /*??? if l==3, middle==2, 0 1 2 3 4, middle should be 2*/
		{
			if(s>min)
				min=s;
			if(l+1-s>max)
				max=l+1-s;
		}
		else
		{
			if(l+1-s>min)
				min=l+1-s;
			if(s>max)
				max=s;
		}
	}
	printf("%d %d", min,max);
	return 0;
}

