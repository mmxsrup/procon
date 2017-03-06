#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int INF = 1e9;
ll dp[110][110][110];
ll memo[110][110];
int main(void){
	int n, m, kumi; cin >> n >> m >> kumi;
	vector<int> c(n);
	rep(i, n) cin >> c[i];
	rep(i, n)rep(j, m) cin >> memo[i][j + 1];

	rep(i, 110)rep(j, 110)rep(k, 110) dp[i][j][k] = INF;

	if(c[0] == 0){
		for (int i = 1; i <= m; ++i){
			dp[0][1][i] = memo[0][i];
		}
	}else{
		dp[0][1][c[0]] = 0;
	}

	for (int i = 0; i < n - 1; ++i){
		for (int j = 1; j <= kumi; ++j){//組数
			for (int k = 1; k <= m; ++k){//最後の色
				if(dp[i][j][k] == INF) continue;
				if(k == c[i + 1]){//同じ色
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
					printf("1 dp[%d][%d][%d] = %lld\n", i + 1, j, k, dp[i + 1][j][k]);
				}else if(c[i + 1] != 0){//色を決められ、色が変わる
					dp[i + 1][j + 1][c[i + 1]] = min(dp[i + 1][j + 1][c[i + 1]], dp[i][j][k]);
					printf("2 dp[%d][%d][%d] = %lld\n", i + 1, j + 1, c[i + 1], dp[i + 1][j + 1][c[i + 1]]);
				}else{//色が好きに決められる
					//色を変えない
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k] + memo[i + 1][k]);
					printf("3 dp[%d][%d][%d] = %lld\n", i + 1, j, k, dp[i + 1][j][k]);
					//変える
					for (int l = 1; l <= m; ++l){
						if(l == k) continue;
						dp[i + 1][j + 1][l] = min(dp[i + 1][j + 1][l], dp[i][j][k] + memo[i + 1][l]);
						printf("4 dp[%d][%d][%d] = %lld\n", i + 1, j + 1, l, dp[i + 1][j][l]);

					}
				}
			}
		}
	}

	ll ans = INF;
	for (int i = 1; i <= m; ++i){
		if(dp[n - 1][kumi][i] == -1)continue;
		ans = min(dp[n - 1][kumi][i], ans);
	}

	if(ans == INF){
		printf("-1\n"); return 0;
	}
	cout << ans << endl;
	return 0;
}