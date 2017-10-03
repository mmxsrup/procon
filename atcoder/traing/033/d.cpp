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
int A[2010];
ll dp[2010][2010]; // dp[i][j] := i日目までの合計がjとなるような場合の数

int main(void) {
	cin >> N;
	A[0] = 0;
	reps(i, 1, N + 1) cin >> A[i];

	rep(i, 2010)rep(j, 2010) dp[i][j] = 0;
	dp[1][A[1]] = 1;
	const int MAX_A = 2000;
	reps(i, 2, N + 1) {
		if(A[i] == -1) {
			ll sum = 0;
			rep(j, MAX_A + 1) {
				(sum += dp[i - 1][j]) %= MOD;
				(dp[i][j] += sum) %= MOD;
				// printf("sum %lld\n", sum);
				// printf("dp[%d][%d] = %lld\n",i,j,dp[i][j] );
			}
		} else {
			ll sum = 0;
			rep(j, A[i] + 1) {
				(sum += dp[i - 1][j]) %= MOD;
				(dp[i][j] += sum) %= MOD;
				// printf("sum %lld\n", sum);
				// printf("dp[%d][%d] = %lld\n",i,j,dp[i][j] );
			}
			rep(j, MAX_A + 1) {
				if(j == A[i]) continue;
				dp[i][j] = 0;
			}
		}
	}
	printf("%lld\n", dp[N][A[N]]);
	return 0;
}