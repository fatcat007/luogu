#include<stdio.h>
#include<string.h>

double d1,c,d2,p0;
long n;
double d[8];
double p[8];

int sp[8];
double f[8];
double s;

int i,j;

int main()
{
	scanf("%lf %lf %lf %lf %d",&d1,&c,&d2,&p0,&n);

	for(i=1;i<=n;i++)
		scanf("%lf %lf",&d[i],&p[i]);
	d[0]=0;
	p[0]=p0;
	
	d[n+1]=d1;
	p[n+1]=0;

	for(i=0;i<=n;i++) /* init sort list */
	{
		sp[i]=i;
	}

	for(i=0;i<n;i++) /* sort by oil price from low to high*/
	{
		int min=i;
		for(j=i+1;j<=n;j++)
		{
			if(p[j]<p[min])
				min=j;
		}
		int t=sp[i];
		sp[i]=sp[min];
		sp[min]=t;
		//printf("sp[%d]=%d p=%lf\r\n", i,sp[i], p[sp[i]]);
	}

	memset(f,0,sizeof(f));
	f[0]=c;

	s=0.0;

	for(i=1;i<=n+1;i++)
	{
		double cc=(d[i]-d[i-1])/d2; /* oil need to reach i */
		double fill = cc;
		for(j=0;j<=n;j++) /* find oil from chip to expensive */
		{
			if(f[sp[j]]>cc)
			{
				s+=p[sp[j]]*cc;
				f[sp[j]]-=cc;
				cc=0;
				break;
			}
			else
			{
				s+=p[sp[j]]*f[sp[j]];
				cc-=f[sp[j]];
				f[sp[j]]=0;
			}
		}
		if(cc>0.0)
			break; /* not enough oil to reach i */

		for(j=0;j<=n;j++) /* swap expensive oil to chipper oil*/
		{
			if(p[j]>p[i])
			{
				fill+=f[j];
				f[j]=0;
			}
		}
		f[i]+=fill; /* fill in oil at i*/
	}

	if(i<=n+1)
		printf("No Solution");
	else
		printf("%.02lf", s);
	return 0;
}

