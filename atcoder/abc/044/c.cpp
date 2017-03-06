#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int x[55];
ll dp[55][55][2550];

int main(void){
	int n, a; cin >> n >> a;
	rep(i, n){
		cin >> x[i]; 
	}

	rep(i, 55)rep(j, 55)rep(k, 2550) dp[i][j][k] = 0;
	dp[0][1][x[0]] = 1; dp[0][0][0] = 1;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j <= n; ++j){
			for (int k = 0; k <= 2500; ++k){
				if(dp[i][j][k] == 0) continue;
				//i + 1番目を選ぶ
				dp[i + 1][j + 1][k + x[i + 1]] += dp[i][j][k];
				//i + 1選ばない
				dp[i + 1][j][k] += dp[i][j][k];
			}
		}
	}

	ll ans = 0;
	for (int j = 1; j <= n; ++j){
		int aim = j * a;
		if(aim <= 2500 && dp[n - 1][j][aim] != 0){
			ans += dp[n - 1][j][aim];
		}
	}
	printf("%lld\n", ans);
	return 0;
}