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

int N, X;
int x[100100], y[100100];
ll c[100100];
ll dp[100010];
vector<pair<int, ll>> G[100100];

void dfs(int u, int p) {
	for(auto t : G[u]) {
		int v = t.fi; ll k = t.se;
		if(p == v) continue;
		dp[v] = dp[u] ^ k;
		dfs(v, u);
	}
}

int main(void) {
	cin >> N >> X;
	rep(i, N - 1) cin >> x[i] >> y[i] >> c[i];
	rep(i, N - 1) x[i]--, y[i]--;

	rep(i, N) G[x[i]].pb(mp(y[i], c[i])), G[y[i]].pb(mp(x[i], c[i]));
	dfs(0, -1);
	dp[0] = 0;
	map<ll, ll> ma;
	rep(i, N) ma[dp[i]]++;

	ll ans = 0;

	for(auto u : ma) {
		ll d = u.fi ^ X;
		// if(d > u.fi) continue;
		if(ma.count(d) == 0) continue;
		
		if(d == u.fi) {
			ans += u.se * (u.se - 1) / 2;
		}else if(d < u.fi){
			ans += u.se * ma[d];
		}
	}
	printf("%lld\n", ans);
	
	return 0;
}