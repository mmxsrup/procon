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

int H, W;
int a[1010][1010];
ll dp[1010][1010];
int dy[] = {1, 0, -1, 0}, dx[] = {0, 1, 0, -1};
int dfs(int y, int x, int py, int px){
	// printf("%d %d %d %d\n", y, x, py, px);
	if(dp[y][x] != 0) return dp[y][x];
	rep(i, 4){
		int ny = y + dy[i], nx = x + dx[i];
		if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
		if(a[y][x] >= a[ny][nx]) continue;
		dp[y][x] += dfs(ny, nx, y, x);
		dp[y][x] %= MOD;
	}
	dp[y][x]++; dp[y][x] %= MOD;
	return dp[y][x];
}

int main(void){
	cin >> H >> W;
	rep(i, H)rep(j, W) cin >> a[i][j];
	ll ret = 0;
	rep(i, H)rep(j, W){
		// printf("ij %d %d\n", i, j);
		ret += dfs(i, j, -1, -1);
		// printf("ret %lld\n", ret);
		ret %= MOD;
	}
	printf("%lld\n", ret);
	return 0;
}