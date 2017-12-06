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
// dp[i][j][k] := i番目までみて, 位置がjで
// k = 0のとき今までの左端の最小値が0になってない
ll dp[3100][3100][2];

int main(void) {
	cin >> N >> M;
	
	rep(i, 3100)rep(j, 3100)rep(k, 2) dp[i][j][k] = 0ll;
	reps(i, 1, N + 1) dp[0][i][0] = 1ll;
	dp[0][0][1] = 1ll;

	rep(i, M)rep(j, N + 1)rep(k, 2) {
		if(dp[i][j][k] == 0) continue;
		if(j) (dp[i + 1][j - 1][k | (j == 1) ? 1 : 0] += dp[i][j][k]) %= MOD;
		if(j) (dp[i + 1][j][k | (j == 1) ? 1 : 0] += dp[i][j][k]) %= MOD;
		if(N - j) (dp[i + 1][j][k] += dp[i][j][k]) %= MOD;
		if(N - j) (dp[i + 1][j + 1][k] += dp[i][j][k]) %= MOD;
	}

	ll ans = 0;
	rep(j, N + 1) (ans += dp[M][j][1]) %= MOD;
	printf("%lld\n", ans);
	return 0;
}