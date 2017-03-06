#include <cstdio>

int main(void){
	
	int N, K;
	long long int ans = 0;

	scanf("%d %d", &N, &K);
	long int a[N];

	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &a[i]);
	}

/*
累積和
0 1 3 7 15 31(累積和)
1 2 4 8 16
*/
	long long ruiseki[N];
	ruiseki[0] = 0;
	
	for (int i = 0; i < N; ++i)
	{
		ruiseki[i + 1] = ruiseki[i] + a[i];
	}

	for (int i = 0; i < N - K + 1; ++i)
	{
		ans += ruiseki[i + K] - ruiseki[i];
	}

	printf("%lld\n", ans);

	return 0;
}