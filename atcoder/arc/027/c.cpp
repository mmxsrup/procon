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
 
int X, Y, N;
int t[310]; ll h[310];
// dp[i][j][k] := i番目まで見て, トッピングをj個買い, チケットをk枚使ったときの価値の最大値
// ll dp[310][310][610];
ll dp[2][310][610];

int main(void) {
	cin >> X >> Y >> N;
	rep(i, N) cin >> t[i] >> h[i];

	rep(i, 2)rep(j, 310)rep(k, 610) dp[i][j][k] = -1;
	dp[0][0][0] = 0;

	rep(i, N){
		rep(j, N)rep(k, X + Y + 1) dp[(i + 1) % 2][j][k] = -1;
		rep(j, N)rep(k, X + Y + 1) {
			if(dp[i % 2][j][k] == -1) continue;
			if(k + t[i] <= X + Y) chmax(dp[(i + 1) % 2][j + 1][k + t[i]], dp[i % 2][j][k] + h[i]);
			chmax(dp[(i + 1) % 2][j][k], dp[i % 2][j][k]);
		}
	}
	ll ans = 0;
	rep(j, 310)rep(k, 610) {
		if(j <= X && k <= X + Y) chmax(ans, dp[N % 2][j][k]);
	}
	printf("%lld\n", ans);
	return 0;
}