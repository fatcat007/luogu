#include<stdio.h>
#include<string.h>

#define N 100000
int f[N]; // N+K<15,���Χ�Ƕ��٣�������Ԥ�裬��������

int v[15]; // ��ǰ�ݹ��״̬��ÿ����ֵ
int m;

int vv[15];
int max;

int n,k;

void dfs(int kk)/* ������kk����ֵ */
{
	int i,j,mm;
	if(kk>k)
	{
		if(m>max)
		{
			max=m;
			for(i=1;i<=k;i++)
				vv[i]=v[i];
		}
		return;
	}

	for(i=v[kk-1]+1,mm=m;i<=mm+1;i++) /*������Χ��[ ��һ���+1����ǰ����ʾ�������ֵ+1 ]*/
	{
		v[kk]=i;
		f[0]=0;
		m=1;
		while(1)
		{
			f[m]=N;
			for(j=1;j<=kk;j++)
			{
				if(m>=v[j] && f[m-v[j]]+1<f[m])
					f[m]=f[m-v[j]]+1;
			}
			//printf("f[m]=%d\r\n",f[m]);
			if(f[m]>n) break;
			m++;
		}
		m--;
		dfs(kk+1);
	}
}

int main()
{
	int i;
	scanf("%d %d",&n,&k);

	v[0]=0;
	m=0;
	max=0;

	dfs(1);

	for(i=1;i<=k;i++)
		printf("%d ",vv[i]);
	printf("\r\nMAX=%d", max);
	return 0;
}
