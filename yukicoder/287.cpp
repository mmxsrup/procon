#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;	
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_hensuu = 10, MAX_SUM = 801;
long long dp[MAX_hensuu][MAX_SUM];//dp[何番目の変数か][合計値] = 整数の組みの個数

int main(void){
	int n; cin >> n;
	rep(i, MAX_hensuu)rep(j, MAX_SUM) dp[i][j] = 0;

	dp[0][0] = 1;//空集合

	for (int i = 1; i <= 8; ++i){
		for (int j = 0; j <= 6 * n; ++j){
			for (int k = 0; k <= n; ++k){
				if(j >= k) dp[i][j] += dp[i - 1][j - k];
			}
		}
	}

	cout << dp[8][6 * n] << endl;
	return 0;
}