#include<stdio.h>
#include<string.h>

int f[100000]; /* f[i]��ʾ����Ϊi���ڵ��������һ���ڵ������߶�*/
int fl;

int d[100000]; /* d[i]��ʾ��į�豸�ܴ����߸߶�*/
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
			if(t<=f[m]) /* ��m���ڵ��㹻�ߣ�m+1���ڵ���������t�߶ȵĵ���*/
				i=m+1;
			else
				j=m;
		}
		//��tΪ��β���ڵ����У��Ӧ����i
		if(t>f[i]) f[i]=t;
		if(i>fl) fl=i;

		i=1;j=dl+1;
		while(i<j)
		{
			m=(i+j)/2;
			if(t>d[m]) /* ��m̨�豸�޷��򵽵���t*/
				i=m+1;
			else
				j=m;
		}
		//��į�豸���Դ��ڵ�t
		if(i>dl) dl=i;
		d[i]=t;
	}
	printf("%d\r\n",fl);
	printf("%d\r\n",dl);
	return 0;	
}

