#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const ll INF = 1e9;
const ll INFF = 1e18;

int N;
int x[1010], y[1010], d[1010], c[1010], u[1010], v[1010];
vector<pair<int, int>> G[1010];
int dp[1010][3000]; //dp[u][p] := 根uのsubtreeでuの強さをpとした場合のコストの最大値

void ds(int i, int j){
	double d = pow(x[i] - x[j], 2) + pow(y[i] - y[j]);
	return (int)(d + 1 - 1e-8); //ex)3->3 3.1->4 3.000000001->3
}

void dfs(int u, int pre){
	if(G[u].size() == 0){
		rep(i, 3000) dp[u][i] = 0;
	}

	for(auto t : u){
		dfs(t.fi, u);
	}
	for(auto t : u){
		int v = t.fi, dist = t.se;
		dfs(v, u);
	}

}

int main(void){
	cin >> N;
	rep(i, N) cin >> x[i] >> y[i];
	rep(i, N) cin >> d[i] >> c[i];
	rep(i, N - 1) cin >> u[i] >> v[i];
	rep(i, N - 1){
		u[i]--, v[i]--;
		int d = ds(u[i], v[i]);
		G[u[i]].pb(mp(v[i], d)), G[v[i]].pb(mp(u[i], d));
	}
	rep(i, 1010)rep(j, 3000) dp[i][j] = INF;
	dfs(0, -1);
	return 0;
}