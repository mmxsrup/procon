#include <stdio.h>

int main(void)
{
	int W, H;
	unsigned long num;
	int i, j, k;
	int WH = 0; //初期化
	unsigned long resultW = 1;
	unsigned long resultH = 1;
	unsigned long resultWH = 1;
	
	scanf("%d", &W);
	scanf("%d", &H);

	WH = (W + H) - 2;

	for (i = 1; i <= W - 1; i++)
	{
		resultW *= i;
	}
	
	for (j = 1; j <= H - 1; j++)
	{
		resultH *= j;
	}

	for (k = 1; k <= WH; k++)
	{
		resultWH *= k;
	}

	num = resultWH / (resultW * resultH);
	
	printf("%ld\n", num % 1000000007);

	return 0;
}