#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int dp[50][2001][3001];
int n, m, s;
int main(void){
	while(1){
		cin >> n >> m >> s;
		if(n == 0 && m == 0 && s == 0) return 0;
		memset(dp, 0, sizeof(dp));
		//rep(i, 50)rep(j, 2001)rep(k, 3001) dp[i][j][k] = 0;
		dp[0][0][0] = 1;
		printf("ready\n");
		for (int i = 0; i < n * n; ++i){
			for (int j = 0; j < m; ++j){
				for (int k = 0; k < s; ++k){
					for (int now = j + 1; now < m; ++now){
						if(k + now > s || now > m) break;//合計overと最大値over
						printf("%d\n", now);
						dp[i + 1][now][k + now] += dp[i][j][k];
						printf("dp[%d][%d][%d] = %d\n", i + 1, now, k + now, dp[i + 1][now][k + now]);
					}
				}
			}
		}
		int sum = 0;
		for (int i = 1; i <= m; ++i){
			sum += dp[n * n][i][s];
		}
		printf("%d\n", sum);
	}
}