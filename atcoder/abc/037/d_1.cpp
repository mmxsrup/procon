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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int h, w;
int a[1010][1010];
ll dp[1010][1010];

ll dfs(int y, int x){
	if(dp[y][x] != -1) return dp[y][x];
	ll ret = 1;
	rep(i, 4){
		int ny = y + dy[i], nx = x + dx[i];
		if(!(0 <= ny && ny < h && 0 <= nx && nx < w)) continue;
		if(a[y][x] < a[ny][nx]){
			ret += dfs(ny, nx);
			ret %= MOD;
		}
	}
	return dp[y][x] = ret;
}

int main(void){
	scanf("%d %d", &h, &w);
	rep(i, h)rep(j, w) scanf("%d", &a[i][j]);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;
	rep(i, h)rep(j, w) ans += dfs(i, j), ans %= MOD;
	printf("%lld\n", ans);
	return 0;
}