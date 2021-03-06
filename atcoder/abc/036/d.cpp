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
int a[100010], b[100010];
vector<int> G[100010];
ll dp[100010][2];

void dfs(int u, int p){
	if(G[u].size() == 1 && G[u][0] == p){
		// printf("k\n");
		dp[u][0] = 1, dp[u][1] = 1;
		return;
	}
	ll white = 1, black = 1;
	for(auto v : G[u]){
		if(v == p) continue;
		dfs(v, u);
		white *= dp[v][0] + dp[v][1];
		white %= MOD;
		black *= dp[v][0];
		black %= MOD;
	}
	dp[u][0] = white;
	dp[u][1] = black;
}

int main(void){
	cin >> N;
	rep(i, N - 1){
		int a, b; cin >> a >> b;
		a--; b--;
		G[a].pb(b), G[b].pb(a);
	}
	dfs(0, -1);
	ll ret = (dp[0][0] + dp[0][1]) % MOD;
	printf("%lld\n", ret);
}