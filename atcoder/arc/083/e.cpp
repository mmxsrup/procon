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
int P[1010], X[1010];

vector<int> G[1010];
int dp[1010][2]; // dp[i][j] := iのsubtreeでiを色j(0:b 1:w)で塗った時
// iのsubstreeの中で!jの合計の最小値

void dfs(int u, int p) {
	int cnt = 0;
	int b = 0, w = 0;
	for(auto v : G[u]) {
		if(v == p)  continue;
		cnt++;
		// printf("u %d v %d\n", u, v);
		dfs(v, u);
		b += min(dp[v][1], X[v]);
		w += min(dp[v][0], X[v]);
		if(dp[v][0] != INF) {
			// printf("1: u %d v %d\n", u, v);
			if(X[u] >= X[v]) chmin(dp[u][0], dp[v][0]); // u:0 v:0
			if(X[u] >= dp[v][0]) chmin(dp[u][1], X[v]); // u:1 v:0
		}
		if(dp[v][1] != INF) {
			// printf("2 :u %d v %d\n", u, v);
			if(X[u] >= dp[v][1]) chmin(dp[u][0], X[v]); // u:0 v:1
			if(X[u] >= X[v])chmin(dp[u][1], dp[v][1]); // u:1 v:1
		}
	}
	if(X[u] >= ) chmin(dp[u][0], dp[v][0]); // u:0 v:0
	if(X[u] >= dp[v][0]) chmin(dp[u][1], X[v]); // u:1 v:0

	if(!cnt) {
		// printf("0: %d\n", u);
		dp[u][0] = dp[u][1] = 0;
	}
}
int main(void) {
	cin >> N;
	rep(i, N - 1) cin >> P[i];
	rep(i, N) cin >> X[i];
	rep(i, N - 1) P[i]--;
	reps(i, 1, N) {
		G[i].pb(P[i - 1]), G[P[i - 1]].pb(i);
		// printf("%d -> %d\n", i, P[i - 1]);
	}

	rep(i, 1010)rep(j, 2) dp[i][j] = INF;
	dfs(0, - 1);
	
	rep(i, N)rep(j, 2) printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	if(dp[0][0] != INF || dp[0][1] != INF) printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
	return 0;
}