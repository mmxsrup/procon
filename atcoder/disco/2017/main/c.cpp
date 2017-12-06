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

int N, M;
int a[100000], b[100000];
ll c[100000];
ll d[310][310];
set<int> v[310];

void dfs(int u, int pre, ll cost) {
	v[u].insert(cost);
	for(auto t : G[u]) {
		int v = t.fi; ll nc = t.se;
		if(v == pre) continue;
		dfs(v, u, cost + nc);
	}
}

void dfs2(int u, int goal, ll cost) {
	if(u == goal) return cost;
	for(auto t : G[u]) {
		int v = t.fi; ll cost = t.se;
		if(v == pre) continue;
		return dfs(v, u, );
	}
}

int main(void) {
	cin >> N >> M;
	rep(i, M) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}
	rep(i, M) d[a[i]][b[i]] = d[b[i]][a[i]] = c[i];

	rep(i, M) {
		ll change(dfs2(b[i], a[i], 0));
	}
	return 0;
}