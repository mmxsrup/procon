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
ll dp[1000100][4];

int main(void) {
	cin >> N;
	dp[0][0] = 1;
	rep(i, N) {
		rep(j, 4) {
			if(j == 0) {
				dp[i + 1][1] += dp[i][j], dp[i + 2][2] += dp[i][j], dp[i + 3][3] += dp[i][j];
				dp[i + 1][1] %= MOD, dp[i + 2][2] %= MOD, dp[i + 3][3] %= MOD;
			} else if(j == 1) {
				dp[i + 2][2] += dp[i][j], dp[i + 3][3] += dp[i][j];
				dp[i + 2][2] %= MOD, dp[i + 3][3] %= MOD;
			} else if(j == 2) {
				dp[i + 3][3] += dp[i][j], dp[i + 1][1] += dp[i][j];
				dp[i + 3][3] %= MOD, dp[i + 1][1] %= MOD;
			} else if(j == 3) {
				dp[i + 1][1] += dp[i][j], dp[i + 2][2] += dp[i][j];
				dp[i + 1][1] %= MOD, dp[i + 2][2] %= MOD;
			}
		}
	}
	ll ans = 0;
	rep(i, 4) ans += dp[N][i], ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}