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
#define int long long
int Gx, Gy, N, F;
int x[55], y[55], c[55];
int dp[55][110][110];

signed main(void){
	cin >> Gx >> Gy >> N >> F;
	rep(i, N) cin >> x[i] >> y[i] >> c[i];
	/*
	vector<pair<double, int>> v;
	rep(i, N){
		int dist = x[i] + y[i];
		double cost = (double)c[i] / (double)dist;
		if(cost < F) v.pb(mp(cost, i));
	}
	sort(all(v));
	*/
	rep(i, 55)rep(j, 110)rep(k, 110) dp[i][j][k] = INF;
	dp[0][0][0] = 0;
	rep(i, N)rep(j, 101)rep(k, 101){
		if(dp[i][j][k] == INF) continue;
		chmin(dp[i + 1][j][k], dp[i][j][k]);
		if(j + x[i] <= 101 && k + y[i] <= 101)
			chmin(dp[i + 1][j + x[i]][k + y[i]], dp[i][j][k] + c[i]);
	}

	/*
	int sx = 0, sy = 0;
	int ret = 0;
	for(auto u : v){
		int i = u.se;
		if(sx + x[i] <= Gx && sy + y[i] <= Gy){
			sx += x[i]; sy += y[i];
			ret += c[i];
		}
	}
	int k = (Gx - sx) + (Gy - sy);
	*/
	int ans = INF;
	rep(i, Gx + 1)rep(j, Gy + 1){
		if(dp[N][i][j] == INF) continue;
		int dist = (Gx - i) + (Gy - j);
		chmin(ans, dp[N][i][j] + dist * F);
	}
	cout << ans << endl;
	return 0;
}