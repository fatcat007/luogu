#include <stdio.h>
#include <string.h>


int p[21][2];
int q[21][2];
int c[21][2];

int i;

int a,n,m,x;
int r;
int mm;

int main()
{
	p[1][0]=1;
	p[1][1]=0; //p0=a+0r

	p[2][0]=0;
	p[2][1]=1; //p1=1r

	c[1][0]=1;
	c[1][1]=0;

	c[2][0]=1;
	c[2][1]=0;

	for(i=3;i<=20;i++)
	{
		p[i][0]=p[i-1][0]+p[i-2][0];//pi=p(i-1)+p(i-2)
		p[i][1]=p[i-1][1]+p[i-2][1];

		c[i][0]=c[i-1][0]+p[i-2][0];
		c[i][1]=c[i-1][1]+p[i-2][1];
	}

	/*for(i=1;i<=20;i++)
		printf("i=%d, c=%da+%dr, p=%da+%dr\r\n", 
			i,c[i][0],c[i][1],p[i][0],p[i][1]);*/

	scanf("%d %d %d %d",&a,&n,&m,&x);

	r=(m-c[n-1][0]*a)/c[n-1][1];
	mm=c[x][0]*a+c[x][1]*r;

	printf("%d",mm);
	return 0;
}

