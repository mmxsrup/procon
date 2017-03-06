#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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

int INF = 100000000;
int dp[20001][256];

void slove(int n, int m){
	vint c(m);
	rep(i, m) scanf("%d", &c[i]);
	vint x(n);
	rep(i, n) scanf("%d", &x[i]);

	rep(i, 20001) rep(j, 256) dp[i][j] = INF;

	dp[0][128] = 0;
	rep(i, n){
		rep(j, 256){
			if(dp[i][j] == INF) continue;
			rep(k, m){
				int now = j + c[k];
				if(now < 0) now = 0;
				if(now > 255) now = 255;
				//dp[何番目のサンプルか≦ 20000][音声信号の値 ≦ 255] = 二乗和の最小値
				dp[i + 1][now] = min(dp[i + 1][now], dp[i][j] + (x[i] - now) * (x[i] - now));
			}
		}
	}
	int ans = 100000000;
	//答えはdp[n][]
	rep(i, 256){
		ans = min(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return;
}

int main(void){
	int n, m;
	while(1){
		scanf("%d %d", &n, &m);
		if(n == 0) break;
		slove(n, m);
	}
	return 0;
}