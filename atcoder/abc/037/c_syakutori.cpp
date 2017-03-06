#include <cstdio>

int main(void){
	
	int N, K;
	//long long int a[1000000];
	long long int sum = 0;
	long long int ans = 0;

	scanf("%d %d", &N, &K);
	long int a[N];

	for (int i = 0; i < N; ++i)
	{
		scanf("%ld", &a[i]);
	}

/*
単純にループしてしまうとTLE
２重ループを回避するためずらして足していく部分だけを足したり引いたりして帳尻を合わせる
ことにより、毎回全てを足さまいで前回のものを利用していける。
*/
	for (int i = 0; i < N - K + 1; ++i)
	{
		if (i == 0)
		{
			for (int j = 0; j < K; ++j)
			{
				sum += a[j];
			}
		}else{
			sum -= a[i - 1];
			sum += a[i + K -1];
		}
		ans += sum;
	}

	printf("%lld\n", ans);

	return 0;
}