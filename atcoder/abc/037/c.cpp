#include <cstdio>

int main(void){
	
	int N, K;
	//long long int a[1000000];
	long long int sum = 0;

	scanf("%d %d", &N, &K);
	long int a[N];

	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &a[i]);
	}

	for (int j = 0; j < N - K + 1; ++j)
	{

		if (K % 2 == 0)
		{
			for (int l = 0; l < (j + K) / 2; ++j)
			{
				sum += (a[l] + a[j + K -1]; 
			}
		}else{
			for (int i = 0; i < (j + K) ; ++i)
			{
				sum += (a[l] + a[j + K -1];
			}
		}
		/*
		for (int l = j; l < j + K; ++l)
		{
			sum += a[l];
		}
		*/
	}

	printf("%lld\n", sum);

	return 0;
}