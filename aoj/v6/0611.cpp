#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
static const int INF = 1e9;

int main(void){
	int n, m; cin >> n >> m;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	vector<int> c(m);
	rep(i, m) cin >> c[i];
	//dp[どこの地点にいるか][何日目]
	int dp[1001][1001];
	rep(i, 1001)rep(j, 1001) dp[i][j] = INF;//初期化
	rep(i, m) dp[0][i] = 0;//初期化
	reps(i, 1, n + 1){
		rep(j, m){
			//漸化式
			dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 1] + d[i - 1] * c[j]);
		}
	}
	int ans = INF;
	//さらに最小の答えを探す
	rep(i, m){
		ans = min(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;
}