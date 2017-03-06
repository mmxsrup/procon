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

int n;
int dp[12][12];
int s[12];
int main(void){
	cin >> n;
	rep(i, n + 1) cin >> s[i];
	rep(i, 12)rep(j, 12) dp[i][j] = INF;
	dp[0][0] = 1;
	for (int i = 0; i <= n; ++i){//進化数
		for (int j = 0; j <= s[i]; ++j){//覚醒数
			// 進化
			if(i) dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j]);//+1枚　覚醒数同じ
			//強化
			for (int k = 0; k < j; ++k){//合わせるやつの覚醒数
				if(j - k - 1 >= 0){
					dp[i][j] = min(dp[i][k] + dp[i][j - k - 1], dp[i][j]);
				}
			}
		}
	}
	for (int i = 0; i <= s[n]; ++i){
		printf("%d ", dp[n][i]);
	}
	printf("\n");
	return 0;
}