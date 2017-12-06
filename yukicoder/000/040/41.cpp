#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 9;
const int INF = 1e9;
const ll INFF = 1e18;

int T;
ll M[10010];
// ll dp[12][100010]; // dp[i][j] := i番目までのコインを見て, 合計がjのときの場合の数
ll dp[100010];

void solve(void) {
	// dp[0][0] = 1;
	int MAX_N = 100010;
	/*
	reps(i, 1, 10)rep(j, MAX_N) {
		// if(dp[i - 1][j] == 0) continue;
		rep(k, MAX_N) {
			if(j + i * k > 100000) break;
			(dp[i][j + i * k] += dp[i - 1][j]) %= MOD;
			// printf("dp[%d][%d](%lld) = dp[%d][%d](%lld)\n", i,j+i*k,dp[i][j + i * k],i-1,j,dp[i-1][j]);
		}
	}
	*/
	dp[0] = 1;
	reps(j, 1, 10) rep(i, 100001) {
		(dp[i + j] += dp[i]) %= MOD;
	}
}

int main(void) {
	cin >> T;
	rep(i, T) cin >> M[i];
	solve();
	rep(i, T) {
		ll sum = M[i] / 111111;
		ll ans = 0;
		// rep(j, sum + 1)	(ans += dp[9][j]) %= MOD;
		rep(j, sum + 1) (ans += dp[j]) %= MOD;
		// printf("sum %lld\n", sum);
		printf("%lld\n", ans);
	}

	return 0;
}