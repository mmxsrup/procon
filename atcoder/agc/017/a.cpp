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


ll dp[55][5010];
int N, P;
int A[55];

int main(void) {
	cin >> N >> P;
	rep(i, N) cin >> A[i];

	dp[0][0] = 1;
	rep(i, N) rep(j, 5010) {
		if(dp[i][j] == 0) continue;
		dp[i + 1][j + A[i]] += dp[i][j];
		dp[i + 1][j] += dp[i][j];
	}
	ll ans = 0;
	rep(i, 5010) if(i % 2 == P) ans += dp[N][i];
	printf("%lld\n", ans);
	return 0;
}