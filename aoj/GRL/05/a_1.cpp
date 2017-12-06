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
ll dist[100010];
vector<pair<int, ll>> G[100010];

int cnt = 0;
int dfs1(int u, int par) {
	// printf("u %d v %d\n", u, par);
	// if(u == 511) cnt++;
	// if(cnt > 10) exit(1);
	ll ma = 0;
	for(auto tm : G[u]) {
		int v = tm.fi; ll cost = tm.se;
		if(v == par) continue;
		// printf("v %d\n", v);
		// chmax(ma, dfs1(v, u) + cost);
		// ma = (ma < dfs1(v, u)) ? (dfs1(v, u)) : (ma)
		ma = max(ma, dfs1(v, u) + cost);
	}
	return dist[u] = ma;
}

ll dfs2(int u, int w, int par) {
	vector<pair<int, ll>> child; // (重み, どこからきたか)
	child.pb(mp(0, -1));
	for(auto tm : G[u]) {
		int v = tm.fi; ll cost = tm.se;
		if(v == par) child.pb(mp(w + cost, v));
		else child.pb(mp(dist[v] + cost, v));
	}
	sort(all(child)); reverse(all(child));
	ll ret = child[0].fi + child[1].fi;
	for(auto tm : G[u]) {
		int v = tm.fi; ll cost = tm.se;
		if(v == par) continue;
		if(v == child[0].se) chmax(ret, dfs2(v, child[1].fi, u));
		else chmax(ret, dfs2(v, child[0].fi, u));
	}
	return ret;
}


int main(void) {
	cin >> n;
	rep(i, n - 1) cin >> s[i] >> t[i] >> w[i];
	rep(i, n - 1) G[s[i]].pb(mp(t[i], w[i]));
	rep(i, n - 1) G[t[i]].pb(mp(s[i], w[i]));
	// printf("k\n");
	dfs1(0, -1);
	auto ret = dfs2(0, 0, -1);
	printf("%lld\n", ret);
	return 0;
}