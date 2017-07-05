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

ll dp[1010][1010]; // dp[i][j] := i人以下のグループでj人を使う場合の場合の数	
int N, A, B, C, D;

int main(void) {
	cin >> N >> A >> B >> C >> D;
	rep(i, 1010)rep(j, 1010) dp[i][j] = 0;
	dp[0][0] = 1;
	
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			if(dp[i][j] == 0) continue;
			// i + 1 人のグループを0個
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			// i + 1 人のグループをk個
			for (int k = C; k <= D; ++k) {
				int num = (i + 1) * k;
				(dp[i + 1][j + num] += dp[i][j]) %= MOD;
			}
		}
	}
	printf("%lld\n", dp[N][N] % MOD);
	return 0;
}