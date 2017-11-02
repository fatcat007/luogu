#include<stdio.h>
#include<string.h>

int main()
{
	int n[3];
	int f[10];
	int i,j,k;
	int dup;
	for(i=123;i<333;i++)
	{
		memset(f,0,sizeof(f));
		dup = 0;
		n[0]=i;
		n[1]=2*i;
		n[2]=3*i;

		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				int r=n[j]%10;
				//printf("r=%d\r\n", r);
				if(!r || f[r])
				{
					dup=1;
					break;
				}
				f[r]=1;
				n[j]/=10;
			}
			if(dup) break;
		}

		if(!dup)
			printf("%d %d %d\r\n", i, 2*i, 3*i);
	}
	return 0;
}

