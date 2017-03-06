#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

int main(void){
	int N;
	int A[100010];
	long long int v;
	long long int sum = 0;
	long long int ans;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	scanf("%lld" ,&v);

	for (int i = 0; i < N; ++i)
	{
		sum += A[i];
	}

	ans = sum - v;
	printf("%lld\n", ans);
}