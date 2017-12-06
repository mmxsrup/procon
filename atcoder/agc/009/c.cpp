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

int N;
ll A, B, S[100010];

ll dp[110][110][110]; // dp[i][j] := Aグループで最後に使ったのがi, Bグループで最後に使ったのがj番目の
int main(void) {
	cin >> N >> A >> B;
	reps(i, 1, N + 1) cin >> S[i];
	S[0] = -INFF + 1;
	rep(i, 1010)rep(j, 1010) dp[i][j] = 0;
	dp[0][0] = 1;
	reps(k, 1, N + 1)REP(i, k)REP(j, k) {
		if(dp[i][j] == 0) continue;
		if(S[i] + A <= S[k]) {
			(dp[k + 1][k][j] += dp[i][j]) %= MOD;
			// printf("1 dp[%d][%d](%lld) = dp[%d][%d](%lld)\n", k, j, dp[k][j], i, j,  dp[i][j]);
		}
		if(S[j] + B <= S[k]) {
			(dp[k + 1][i][k] += dp[i][j]) %= MOD;
			// printf("2 dp[%d][%d](%lld) = dp[%d][%d](%lld)\n", i, k, dp[i][k], i, j,  dp[i][j]);
		}
	}
	reps(i, 1, N + 1)rep(j, N)rep(k, N) {
		if(dp[i][j][k] == 0) continue;
		if(S[i] + A <= S[k]) {
			(dp[k + 1][])
		}
	}
	ll ans = 0;
	rep(i, N) (ans += dp[i][N]) %= MOD;
	rep(j, N) (ans += dp[N][j]) %= MOD;
	printf("%lld\n", ans);
	return 0;
}