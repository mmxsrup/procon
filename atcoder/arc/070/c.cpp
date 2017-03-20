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
int dp[410][410]; // ibannme hidari
int l[100010], r[100010];
int dist[100010];
int slv(int L, int R, int K){
	int mi = INF;
	reps(i, L, R + 1){
		chmin(mi, abs(i - K));
	}
	return mi;
}

int main(void){
	cin >> N;
	rep(i, N) cin >> l[i] >> r[i];
	rep(i, N) dist[i] = r[i] - l[i];
	rep(i, 410)rep(j, 410) dp[i][j] = INF;
	reps(i, 1, 401){
		dp[0][i] = abs(l[0] - i);
	}
	dp[0][l[0]] = 0;
	reps(i, 1, N)for (int j = 1; j <= 400; ++j){
		if(dp[i - 1][j] == INF) continue;
		for (int k = 1; k <= 400; ++k){ //左端
			if((k + dist[i]< j) || (dist[i - 1] + j < k)) continue;
			chmin(dp[i][k], dp[i - 1][j] + abs(l[i] - k));
			// printf("dp[%d][%d] = %d, dp[%d][%d](%d) %d\n", i, k, dp[i][k], i-1, j, dp[i-1][j], abs(l[i]-k));
		}
	}
	int ans = INF;
	rep(i, 410)chmin(ans, dp[N - 1][i]);
	printf("%d\n", ans);
	return 0;
}