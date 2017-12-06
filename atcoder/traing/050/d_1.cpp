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

int N, K;
string s;
int dp[310][310][310]; // dp[i][j][k] := i番目まで見て1の最大値がj, 0の最大値がj

int main(void) {
	cin >> N >> K;
	cin >> s;
	rep(i, 310)rep(j, 310)rep(k, 310) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	rep(i, N) {
		if (s[i] == '1') {
			rep(j, 310)rep(k, 310) {
				if(dp[i][j][k] == 0) continue;
				(dp[i + 1][j + 1][max(0, k - 1)] += dp[i][j][k]) %= MOD;
			}
		} else if(s[i] == '0') {
			rep(j, 310)rep(k, 310) {
				if(dp[i][j][k] == 0) continue;
				(dp[i + 1][max(0, j - 1)][k + 1] += dp[i][j][k]) %= MOD;
			}
		} else {
			rep(j, 310)rep(k, 310) {
				if(dp[i][j][k] == 0) continue;
				(dp[i + 1][j + 1][max(0, k - 1)] += dp[i][j][k]) %= MOD;
				(dp[i + 1][max(0, j - 1)][k + 1] += dp[i][j][k]) %= MOD;
			}
		}
	}
	ll ans = 0;
    rep(i, N + 1 )rep(j, N + 1){
        if (i + j <= K) (ans += dp[N][i][j]) %= MOD;
    }
	printf("%lld\n", ans);
	return 0;
}