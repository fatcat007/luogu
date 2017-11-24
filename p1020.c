#include<stdio.h>
#include<string.h>

int f[100000]; /* f[i]表示长度为i的炮弹序列最后一个炮弹的高度，如果有多个长度为i的炮弹序列，则记录末尾较高的一个*/
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
	while(scanf("%d",&t)!=EOF)
	{
		i=0;j=fl;
		while(i<j)
		{
			m=(i+j)/2;
			if(f[m]>=t) /* 第m个炮弹足够高，m+1个炮弹可以射下t高度的导弹*/
				i=m+1;
			else
				j=m;
		}
		//[0,i)的序列末尾高度比大于等于t
		f[i]=t; //更新i位置的高度
		if(i+1>fl) fl=i+1;

		i=0;j=dl;
		while(i<j)
		{
			m=(i+j)/2;
			if(d[m]<t) /* 第m台设备无法打到导弹t*/
				i=m+1;
			else
				j=m;
		}
		//第i台设备可以打到炮弹t
		if(i+1>dl) dl=i+1;
		d[i]=t;
	}
	printf("%d\r\n%d",fl,dl);
	return 0;
}

