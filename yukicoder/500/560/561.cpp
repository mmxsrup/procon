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

int N, D;
int T[110], K[110];
int dp[110][2];

int main(void) {
	cin >> N >> D;
	rep(i, N)cin >> T[i] >> K[i];

	rep(i, 110)rep(j, 2) dp[i][j] = -1;
	dp[0][0] = 0;
	rep(i, N)rep(j, 2) {
		if(dp[i][j] == -1) continue;
		if(j) {
			chmax(dp[i + 1][j], dp[i][j] + K[i]); // そのまま
			chmax(dp[i + 1][0], dp[i][j] + T[i] - D);
		}else{
			chmax(dp[i + 1][j], dp[i][j] + T[i]); // そのまま
			chmax(dp[i + 1][1], dp[i][j] + K[i] - D);
		}
		// printf("dp[%d][0] = %d\n", i+1, dp[i + 1][0]);
		// printf("dp[%d][1] = %d\n", i+1, dp[i + 1][1]);
	}
	printf("%d\n", max(dp[N][0], dp[N][1]));
	return 0;
}