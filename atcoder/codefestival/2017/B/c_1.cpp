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
 
 
int n, m;
int a[100010], b[100010];
vector<int> G[100010];
unordered_set_set<pair<int, int> > se;
unordered_set<pair<int, int>> tmp;
 
bool f;
ll ans = 0;
void dfs(int u, int p, int start, int cnt) {
	// printf("u %d start %d cnt %d\n", u, start, cnt);
	if(cnt == 3) {
		if(start == u) return;
		if(se.count(mp(start, u)) == 0) {
			// printf("ins %d %d\n", start, u);
			tmp.insert(mp(min(start, u), max(start, u)));
		}
		return;
	}
	for(auto v : G[u]) {
		if(v == p) continue;
		// printf("v %d\n", v);
		dfs(v, u, start, cnt + 1);
	}
}
int main(void) {
	cin >> n >> m;
	rep(i, m) scanf("%d %d", &a[i], &b[i]);
	rep(i, m) a[i]--, b[i]--;
 
	rep(i, m) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);
	rep(i, m) se.insert(mp(a[i], b[i])), se.insert(mp(b[i], a[i]));
 
 
 
	rep(i, 10) {
		f = false;
		tmp.clear();
		rep(i, n) dfs(i, i, i, 0);
		// printf("size %d\n", tmp.size());
		if(tmp.size()) f = true;
		ans += (ll)tmp.size();
		for(auto t : tmp) {
			G[t.fi].pb(t.se); G[t.se].pb(t.fi);
			se.insert(mp(t.fi, t.se)), se.insert(mp(t.se, t.fi));
		}
		if(!f) break;
	}
	printf("%lld\n", ans);
	return 0;
}