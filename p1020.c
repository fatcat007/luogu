#include<stdio.h>
#include<string.h>

int f[100000]; /* f[i]表示长度为i的炮弹序列最后一个炮弹的最大高度*/
int fl;

int d[100000]; /* d[i]表示第i台设备能打的最高高度*/
int dl;

int t;
int i,j;
int m;
int main()
{
	fl=0;
	dl=0;
	while(scanf("%d",&t))
	{
		i=1;j=fl+1;
		while(i<j)
		{
			m=(i+j)/2;
			if(t<=f[m]) /* 第m个炮弹足够高，m+1个炮弹可以射下t高度的导弹*/
				i=m+1;
			else
				j=m;
		}
		//以t为结尾的炮弹序列，最长应该是i
		if(t>f[i]) f[i]=t;
		if(i>fl) fl=i;

		i=1;j=dl+1;
		while(i<j)
		{
			m=(i+j)/2;
			if(t>d[m]) /* 第m台设备无法打到导弹t*/
				i=m+1;
			else
				j=m;
		}
		//第i台设备可以打到炮弹t
		if(i>dl) dl=i;
		d[i]=t;
	}
	printf("%d\r\n",fl);
	printf("%d\r\n",dl);
	return 0;	
}

