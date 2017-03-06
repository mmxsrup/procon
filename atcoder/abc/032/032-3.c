#include <stdio.h>

int main (void)
{
	int i, j, l, k;
	int flag = 1;
	long long int mul = 1;
	long long int min = 1000000000;
	int count = 0;
	int N;
	long long int K;
	scanf("%d %lld", &N, &K);

//K == 0の例外？を除く
	if (K == 0)
	{
		printf("0\n");
		return 0;
	}

	long int S[N + 1];

	for (i = 0; i < N; ++i)
	{
		scanf("%ld", &S[i]);
		//sの配列の中に少なくとも１つ０があればNをプリントすればいい
		if (S[i] == 0)
			{
				printf("%d\n", N);
				return 0;
			}	
	}

	while (flag == 1){
		for (int j = 1; j <= N; j++) //jはかける数字の数
		{
			for (l = 0; l < N; l++) //lは何番目の数字からかけるか
			{
				for (k = l; k < j + l; k++)
				{
					mul *= S[k];
					if (min > mul)
					{
						min = mul
					}
					
				}
				if (mul <= K) //K以下であればおk
						flag = 1;	
			}
		}
	}

	printf("%d\n", j);

	return 0;
}