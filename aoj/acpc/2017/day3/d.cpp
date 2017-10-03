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

int N, C;
int a[110], b[110], c[110];
// dp[i][j][k] := i番目まで見て, Aの好感度がjで
// コストがcの時の Bの好感度の最大値
int dp[10010][110]; 

int main(void) {
	cin >> N >> C;
	rep(i, N) cin >> a[i] >> b[i] >> c[i];
	rep(j, 10010)rep(k, 110) dp[j][k] = -1;
	dp[0][0] = 0;
	rep(i, N)REP(j, 10001)REP(k, C) {
		if(dp[j][k] == -1) continue;
		// 使わない
		chmax(dp[j][k], dp[j][k]);
		if(k + c[i] > C) continue;
		// Aを使う
		chmax(dp[j + a[i]][k + c[i]], dp[j][k] + b[i]);
		// Bを使う
		chmax(dp[j + b[i]][k + c[i]], dp[j][k] + a[i]);
		/*
		// もともと高い方がまだ高い
		if(j + b[i] >= dp[i][j][k] + a[i]) chmax(dp[i + 1][j + b[i]][k + c[i]], dp[i][j][k] + a[i]);
		// もともと高い方が低くなった
		else chmax(dp[i + 1][dp[i][j][k] + a[i]][k + c[i]], j + b[i]);
		*/
	}

	int ans = 0;
	rep(i, 10001)rep(j, C + 1) chmax(ans, min(i, dp[i][j]));
	printf("%d\n", ans);
	return 0;
}