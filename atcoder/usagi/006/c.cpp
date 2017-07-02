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
int q;
int v[100010], d[100010], c[100010];
int color[100010][12];
vector<int> G[100010];

void dfs(int u, int p, int cnt, int dist, int iro){
	if(cnt >= dist) return;
	for(auto v : G[u]) {
		if(v == p) continue;
		if(color[v][dist - cnt - 1] != 0) continue;
		for (int i = dist - cnt - 1; i >= 0; --i) {
			if(color[v][i] == 0)color[v][i] = iro;
			else break;
		}
		
		dfs(v, u, cnt + 1, dist, iro);
	}
}

int main(void) {
	cin >> n >> m;
	rep(i, m) cin >> a[i] >> b[i];
	cin >> q;
	rep(i, q) cin >> v[i] >> d[i] >> c[i];
	rep(i, m) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);

	for (int i = q - 1; i >= 0; --i) {
		if(color[v[i]][d[i]] != 0) continue;
		for (int j = d[i]; j >= 0; --j) {
			if(color[v[i]][j] == 0) color[v[i]][j] = c[i];
			else break;
		}
		
		dfs(v[i], -1, 0, d[i], c[i]);
	}
	// reps(i, 1, n + 1){rep(j, 12)printf("%d ", color[i][j]); printf("\n");}
	reps(i, 1, n + 1)printf("%d\n", color[i][0]);
	return 0;
}

