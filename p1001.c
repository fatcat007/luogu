#include <stdio.h>

/* 2的31次方减去1等于多少？ 大于2*10的9次方, 所以int类型可以允许10的9次方内的加减*/
int main()
{
	int a,b;
	scanf("%d %d", &a,&b);
	printf("%d", a+b);
	return 0;
}

