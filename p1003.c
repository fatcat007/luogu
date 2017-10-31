

#include <stdio.h>
#include <string.h>

int pos[100000][4];

int main()
{
	int n;
	scanf("%d",&n);

	int i;
	for(i=0;i<n;i++)
	{
		int a,b,g,k;
		scanf("%d %d %d %d",&a,&b,&g,&k);
		pos[i][0]=a;
		pos[i][1]=b;
		pos[i][2]=g;
		pos[i][3]=k;
	}
	int x,y;
	scanf("%d %d",&x,&y);
	for(i=n-1;i>=0;i--)
		if(x>=pos[i][0] && y>=pos[i][1] && x<=pos[i][0]+pos[i][2] && y<=pos[i][1]+pos[i][3])
			break;

	if(i<0)
		printf("-1");
	else
		printf("%d", i+1);
	return 0;
}

