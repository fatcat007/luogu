#include<stdio.h>
#include<string.h>

int f[100000]; /* f[i]��ʾ����Ϊi���ڵ��������һ���ڵ��ĸ߶ȣ�����ж������Ϊi���ڵ����У����¼ĩβ�ϸߵ�һ��*/
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
	while(scanf("%d",&t)!=EOF)
	{
		i=0;j=fl;
		while(i<j)
		{
			m=(i+j)/2;
			if(f[m]>=t) /* ��m���ڵ��㹻�ߣ�m+1���ڵ���������t�߶ȵĵ���*/
				i=m+1;
			else
				j=m;
		}
		//[0,i)������ĩβ�߶ȱȴ��ڵ���t
		f[i]=t; //����iλ�õĸ߶�
		if(i+1>fl) fl=i+1;

		i=0;j=dl;
		while(i<j)
		{
			m=(i+j)/2;
			if(d[m]<t) /* ��m̨�豸�޷��򵽵���t*/
				i=m+1;
			else
				j=m;
		}
		//��į�豸���Դ��ڵ�t
		if(i+1>dl) dl=i+1;
		d[i]=t;
	}
	printf("%d\r\n%d",fl,dl);
	return 0;
}

