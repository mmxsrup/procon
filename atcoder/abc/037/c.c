#include <stdio.h>

int main(void){
	
	int N, K;
	long long int a[1000000];
	long long int sum = 0;

	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &a[i]);
	}

	for (int j = 0; j < N - K + 1; ++j)
	{
		for (int l = j; l < j + K; ++l)
		{
			sum += a[l];
		}
	}

	printf("%lld\n", sum);

	return 0;
}