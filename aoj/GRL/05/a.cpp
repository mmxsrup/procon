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

int n;
int s[100010], t[100010], w[100010];
vector<pair<int, int>> G[100010];
int dp[100010];

void dfs1(int idx, int par){
	for(auto u : G[idx]){
		if(u.fi == par) continue;
		dfs1(u.fi, idx);
		chmax(dp[idx], dp[u.fi] + u.se);
	}
}

int dfs2(int idx, int d_par, int par){
	vector<pair<int, int>> d_child;
	child.pb(mp(0, -1)); //番兵
	for(auto u : G[idx]){
		if(u.fi == par) d_child.pb(mp(d_par + u.se, u.fi));
		else d_child.pb(mp(u.se + dp[u.fi], u.fi));
	}
	sort(all(d_child)); reverse(all(d_child));
	int ret = d_child[0].fi + d_child[1].fi; // 最大から2つ
	for(auto u : G[idx]){
		if(u.fi == par) continue;
		chmax(ret, dfs2(u.fi, d_child[d_child[0].se == u.fi].fi, idx));
	}
	return ret;
}

int main(void){
	cin >> n;
	rep(i, n - 1) cin >> s[i] >> t[i] >> w[i];
	rep(i, n - 1) G[s[i]].pb(mp(t[i], w[i])), G[t[i]].pb(mp(s[i], w[i]));

	dfs(0, -1);

}