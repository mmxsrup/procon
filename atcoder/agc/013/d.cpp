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
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N, M;
// dp[i][j][k] := i番目までみて, 位置がjで, いままでの左端がjの時の場合の数
ll dp[310][310][310];

int main(void) {
	cin >> N >> M;
	assert(N <= 300 && M <= 300);
	
	rep(i, 310)rep(j, 310)rep(k, 310) dp[i][j][k] = 0ll;
	rep(i, N + 1) dp[0][i][i] = 1ll;

	rep(i, M)rep(j, N + 1)rep(k, N + 1) {
		if(dp[i][j][k] == 0) continue;
		if(j) (dp[i + 1][j - 1][min(k, j - 1)] += dp[i][j][k]) %= MOD;
		if(j) (dp[i + 1][j][min(k, j - 1)] += dp[i][j][k]) %= MOD;
		if(N - j) (dp[i + 1][j][k] += dp[i][j][k]) %= MOD;
		if(N - j) (dp[i + 1][j + 1][k] += dp[i][j][k]) %= MOD;
	}

	ll ans = 0;
	rep(j, N + 1) (ans += dp[M][j][0]) %= MOD;
	printf("%lld\n", ans);
	return 0;
}