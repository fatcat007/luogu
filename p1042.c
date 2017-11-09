#include<stdio.h>
#include<string.h>

char r[21];
int rl;

int win[2][10000]; /* win[0][j] 11分制j局得分, win[1][j] 21分制j局得分 */
int loss[2][10000];
int set[2]; /* set[0] 11分制局数，21分局数*/

int i;

int main()
{
	while(1)
	{
		scanf("%s",r);
		rl=strlen(r);

		for(i=0;i<rl;i++)
		{
			if(r[i]=='W')
			{
				win[0][set[0]]++;
				win[1][set[1]]++;
			}
			else if(r[i]=='L')
			{
				loss[0][set[0]]++;
				loss[1][set[1]]++;
			}
			else if(r[i]=='E')
			{
				break;
			}	
			//printf("set=%d, win=%d,loss=%d\r\n", set[0], win[0][set[0]], loss[0][set[0]]);
			if((win[0][set[0]]>=11 || loss[0][set[0]]>=11) &&
				(win[0][set[0]]>=loss[0][set[0]]+2 || 
				 loss[0][set[0]]>=win[0][set[0]]+2))
				set[0]++;

			if((win[1][set[1]]>=21 || loss[1][set[1]]>=21) &&
				(win[1][set[1]]>=loss[1][set[1]]+2 || 
				 loss[1][set[1]]>=win[1][set[1]]+2))
				set[1]++;
		}
		if(r[i]=='E')
			break;
	}

	for(i=0;i<=set[0];i++)
		printf("%d:%d\r\n", win[0][i],loss[0][i]);
	printf("\r\n");
	for(i=0;i<=set[1];i++)
		printf("%d:%d\r\n", win[1][i],loss[1][i]);

	return 0;
}

