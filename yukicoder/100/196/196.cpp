#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, k;
vector<int> G[2020];
int size[2010];//size[i]:=i以下の木の頂点の数
int dp[2010][2020];//dp[i][j]:=i以下の木で黒い頂点をj個作る時の数

int dfs(int u, int pre){
	//post-order
	for(auto v : G[u]){
		if(v == pre) continue;
		dfs(v, u);
	}
	//uを処理
	size[u] = 1;
	for(auto v : G[u]){
		if(v == pre) continue;
		size[u] += size[v];
	}
	return size[u];
}

void ki_dp(int u, int pre){
	printf("top %d\n", u);
	//post-order
	for(auto v : G[u]){
		if(v == pre)continue;
		ki_dp(v, u);
	}	
	//uを処理
	dp[u][0] = 1;//一つも塗らない
	dp[u][size[u]] = 1;//全部塗る
	for(auto v : G[u]){
		if(v == pre) continue;
		// rep(i, size[u] + 1)rep(j, size[u] + 1){
		for (int i = size[u]; i >= 0; --i)for (int j = size[u]; j >= 0; --j){
			if(i + j < size[u]){
				dp[u][i + j] += dp[u][i] * dp[v][j];
				printf("dp[%d][%d](%d) * dp[%d][%d](%d) = dp[%d][%d] = %d\n", u, i, dp[u][i], v, j, u, i + j, dp[u][i + j]);
				dp[u][i + j] %= MOD;
			}
		}
	}
}

int main(void){
	scanf("%d %d", &n, &k);
	rep(i, n - 1){
		int a, b;
		scanf("%d %d", &a, &b);
		G[a].pb(b);
		G[b].pb(a);
	}
	dfs(0, -1);
	rep(i, n)printf("i:%d %d\n", i, size[i]);
	ki_dp(0, -1);
	printf("%d\n", dp[0][k]);
	return 0;
}