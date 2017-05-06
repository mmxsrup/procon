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
int a[20];

ll dp[20][2];

int main(void){
	cin >> N;
	rep(i, N) cin >> a[i];

	rep(i, 20) dp[i][0] = -INFF;
	rep(i, 20) dp[i][1] = INFF;
	dp[1][0] = dp[1][1] = a[0];

	reps(i, 1, N)rep(j, 2){
		ll ma = -INFF, mi = INFF;
		// printf("%lld\n", dp[i][j]);
		chmax(ma, dp[i][j] * a[i]), chmin(mi, dp[i][j] * a[i]);
		chmax(ma, dp[i][j] + a[i]), chmin(mi, dp[i][j] + a[i]);
		chmax(ma, dp[i][j] - a[i]), chmin(mi, dp[i][j] - a[i]);
		if(a[i] != 0)chmax(ma, dp[i][j] / a[i]), chmin(mi, dp[i][j] / a[i]);
		chmax(dp[i + 1][0], ma);
		chmin(dp[i + 1][1], mi);
		// printf("%lld %lld\n", ma, mi);
	}

	ll ans = -INFF;
	if(dp[N][0] != -INFF) chmax(ans, dp[N][0]);
	if(dp[N][1] != INFF) chmax(ans, dp[N][1]);
	printf("%lld\n", ans);
	return 0;
}