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

//dp[i][j] := i番目までのコンテストで、j問解いた時の順位の合計の最小値
// int dp[5010][20010];
int dp[2][20010];
int n, p;
int score[5010][5];

int main(void){
	cin >> n >> p;
	rep(i, n) {
		cin >> score[i][0] >> score[i][1] >> score[i][2];
		score[i][3] = 1;
	}

	rep(i, 2)rep(j, 20010) dp[i][j] = INF;
	dp[0][0] = 0;

	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= p; ++j){
			for (int k = 0; k <= 3; ++k){
				if(j + k <= p){
					dp[1][j + k] = min(dp[0][j] + score[i][k], dp[1][j + k]);
				}
			}
		}
		for (int j = 0; j <= p; ++j){
			dp[0][j] = dp[1][j];
			dp[1][j] = INF;
		}
	}
	printf("%.9f\n", (double)dp[0][p] / (double)n);
	return 0;
}