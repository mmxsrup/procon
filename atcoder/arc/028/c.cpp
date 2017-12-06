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

int N;
int p[100100];
vector<int> G[100100];
int par[1000100];
int dp[1000100];

int dfs(int u, int pre) {
	par[u] = pre;
	int ret = 1;
	for(auto v : G[u]) {
		if(v == pre) continue;
		ret += dfs(v, u);
	}
	return dp[u] = ret;
}

int main(void) {
	cin >> N;
	rep(i, N - 1) cin >> p[i];
	rep(i, N - 1) G[i + 1].pb(p[i]), G[p[i]].pb(i + 1);
	dfs(0, -1);
	// rep(i, N) printf("%d ", dp[i]);
	// printf("\n");
	rep(u, N) {
		int ans = 0, sum = 0;
		for(auto v : G[u]) {
			if(v == par[u]) continue;
			chmax(ans, dp[v]);
			sum += dp[v];
		}
		chmax(ans, N - sum - 1);
		printf("%lld\n", ans);
	}
	return 0;
}