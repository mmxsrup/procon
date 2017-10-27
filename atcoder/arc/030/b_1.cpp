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

int n, x;
int h[110];
int a[110], b[110];
vector<int> G[110];
bool used[110];

bool dfs(int u, int p) {
	// printf("%d %d\n", u, p);
	bool flag = false;
	for(auto v : G[u]) {
		if(p == v) continue;
		flag |= dfs(v, u);
	}
	return used[u] = flag | h[u];
}

int ans = 0;
void dfs2(int u, int p) {
	for(auto v : G[u]) {
		if(p == v) continue;
		if(!used[v]) continue;
		ans += 2;
		dfs2(v, u);
	}
}

int main(void) {
	cin >> n >> x;
	rep(i, n) cin >> h[i];
	rep(i, n - 1) cin >> a[i] >> b[i];
	rep(i, n - 1) a[i]--, b[i]--;
	rep(i, n - 1) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);

	x--;
	dfs(x, -1);
	dfs2(x, -1);
	printf("%d\n", ans);
	return 0;
}