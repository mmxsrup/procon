#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int mod = 100000;

//i = 0　右向きに曲がれる
//i = 1　上向きに曲がれる
//i = 2　右向きに曲がれない
//i = 3　上向きに曲がれない
//dp[s][h][w] := 状態s座標(w, h)
ll dp[4][101][101];

int main(void){
	int w, h;
	while(1){
		cin >> w >> h;
		if(w == 0 && h == 0) return 0;
		rep(i, 2)rep(j, 101)rep(k, 101)dp[i][j][k] = 0;
		rep(i, 4) dp[i][0][0] = 1;

		for (int i = 0; i < h; ++i){
			for (int j = 0; j < w; ++j){
				for (int k = 0; k < 4; ++k){
					//右に曲がれる(一つ左のマス目から直進してきた時)
					(dp[0][i][j] += (dp[0][i][j - 1] + dp[2][j - 1])) %= mod;
					//上に曲がれる
					(dp[1][i][j] += (dp[1][i - 1][j] + dp[3][i - 1][j])) %= mod;
					//右に曲がれない(一つ下のマス目から上に曲がってきた時)
					(dp[2][i][j] += dp[1][i - 1][j]) %= mod;
					//上に曲がれない(一つ左のマス目から右に曲がってきた時)
					(dp[3][i][j] += dp[1][i][j - 1]) %= mod;
				}
			}
		}
	}

	ll sum = 0;
	rep(i, 4) (sum += dp[i][h - 1][w - 1]) %= mod;
	printf("%lld\n", sum % mod);
}