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

int n, m;
int u[220];
vector<pair<int, int> > dist[220];
//dp[i][j] := 頂点iのサブツリーの中で、時間jでiに戻ってくる場合の税収の最大値
int dp[220][2200];

void ki_dp(int s, int pa){ //今　親
	dp[s][0] = u[s]; //0秒でu[s]はもらえる
	for (auto t : dist[s]){ //s -> t.fi
 		if(s != t.fi && pa != t.fi){
 			//ボトムアップで値を決定していく
 			ki_dp(t.fi, s);
 			for (int i = m; i >= 0; --i){
 				for (int j = 0; j <= m; ++j){
 					int cost = i + j + t.se * 2;
 					if(cost <= m){
 						chmax(dp[s][cost], dp[s][i] + dp[t.fi][j]);
 					}
 				}
 			}
 		}
	}
}

int main(void){
	cin >> n >> m;
	rep(i, n) cin >> u[i];
	rep(i, n - 1){
		int a, b, c;
		cin >> a >> b >> c;
		dist[a].pb(mp(b, c));
		dist[b].pb(mp(a, c));
	}
	ki_dp(0, -1);
	int ans = 0;
	rep(i, m + 1){
		chmax(ans, dp[0][i]);
	}

	printf("%d\n", ans);
	return 0;
}