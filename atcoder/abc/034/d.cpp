#include <cstdio>
#include <map>
#include <std::vector<char> v;>
#include <algorithm>

typedef long long ll;
using namespace std;

int K, N;
ll w[1010];
int p[1010];

bppl slove(double ans){

	//目標の塩の量から足りない塩の量を計算
	for (int i = 0; i < n; ++i)
	{

		salt[i] = w[i] * (p[i] - ans) / 100;
	}

	//塩が足りているかを合計する
	double sum = 0.0;
	for (int i = 0; i < k; ++i)
	{
		sum += salt[i];
	}
	//塩が足りてるかで戻り値
	return sum >= 0;
}


int main(void){
	//入力
	for (int i = 0; i < n - 1; ++i)				
	{
		scanf("%d %d", &K, &N);
	}

	double min = 0;
	double max = 100;

	for (int i = 0; i < 100; ++i)
	{
		mid = (max + min) / 2;
		if (check(mid))
			min = mid;
		else
			max = mid;
	}
}