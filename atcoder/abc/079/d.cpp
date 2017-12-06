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

int c[12][12];
int a[220][220];
ll dp[12][12];

void solve() {
	rep(i, 12)rep(j, 12) dp[i][j] = INF;
	rep(i, 10)rep(j, 10) {
		if(c[i][j] == -1) continue;
		dp[i][j] = c[i][j];
	}

	rep(k, 10)rep(i, 10)rep(j, 10) {
		dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	}
}
int main(void) {
	int h, w; cin >> h >> w;
	rep(i, 10)rep(j, 10) cin >> c[i][j];
	rep(i, h)rep(j, w) cin >> a[i][j];
	solve();
	ll sum = 0;
	rep(i, h)rep(j, w) {
		if(a[i][j] == -1) continue;
		// printf("%d %lld\n", a[i][j], dp[a[i][j]][1]);
		sum += dp[a[i][j]][1];
	}
	printf("%lld\n", sum);
	return 0;
}