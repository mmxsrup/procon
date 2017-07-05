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
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int h, w, s;
int U[35][35];
int allsum = 0;
int sum[35][35];
// dp[y1][x1][y2][x2] := 左上(y1, x1), 右下(y2, x2)の長方形を考えた時の, 
// グループの分け方の最大数, 最大の予備力
pair<int, int> dp[35][35][35][35];

void sum2D(int h, int w) {
	rep(y, h + 1)rep(x, w + 1) sum[y][x] = 0;
	rep(y, h)rep(x, w) sum[y + 1][x + 1] = U[y][x]; // まずは埋め込む
	rep(y, h + 1)rep(x, w) sum[y][x + 1] += sum[y][x]; // 横
	rep(y, h)rep(x, w + 1) sum[y + 1][x] += sum[y][x]; // 縦
}
int calcSum(int y1, int x1, int y2, int x2) {
	return sum[y2 + 1][x2 + 1] - sum[y2 + 1][x1] - sum[y1][x2 + 1] + sum[y1][x1];
}

pair<int, int> dfs(int y1, int x1, int y2, int x2) {
	if(dp[y1][x1][y2][x2] != make_pair(0, INF)) return dp[y1][x1][y2][x2];
	
	auto ret = make_pair(1, s - (allsum - calcSum(y1, x1, y2, x2)));

	for (int i = x1; i < x2; ++i){
		if(s - (allsum - calcSum(y1, x1, y2, i)) < 0) continue;
		if(s - (allsum - calcSum(y1, i + 1, y2, x2)) < 0) continue;
		auto ret1 = dfs(y1, x1, y2, i);
		auto ret2 = dfs(y1, i + 1, y2, x2);
		chmax(ret, make_pair(ret1.fi + ret2.fi, min(ret1.se, ret2.se)));
	}

	for (int i = y1; i < y2; ++i){
		if(s - (allsum - calcSum(y1, x1, i, x2)) < 0) continue;
		if(s - (allsum - calcSum(i + 1, x1, y2, x2)) < 0) continue;
		auto ret1 = dfs(y1, x1, i, x2);
		auto ret2 = dfs(i + 1, x1, y2, x2);
		chmax(ret, make_pair(ret1.fi + ret2.fi, min(ret1.se, ret2.se)));
	}
	return dp[y1][x1][y2][x2] = ret;
}

int main(void) {
	while(1) {
		scanf("%d %d %d", &h, &w, &s);

		if(h == 0 && w == 0 && s == 0) break;
		rep(i, h)rep(j, w) scanf("%d", &U[i][j]);
		allsum = 0;
		rep(i, h)rep(j, w) allsum += U[i][j];
		sum2D(h, w);
		rep(i, 35)rep(j, 35)rep(k, 35)rep(l, 35) dp[i][j][k][l] = make_pair(0, INF);
		auto ans = dfs(0, 0, h - 1, w - 1);
		printf("%d %d\n", ans.fi, ans.se);
	}
	return 0;
}
