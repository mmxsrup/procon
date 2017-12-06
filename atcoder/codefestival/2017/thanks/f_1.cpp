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
 
 
int N, K;
int a[100010];
ll dp[100010][600];
 
int main(void) {
	cin >> N >> K;
	rep(i, N) cin >> a[i];
 
	ll cnt = 0;
	if(N <= 24) {
	// if(N == 1){
		for (int mask = 0; mask < (1<<N); ++mask) {
			ll sum = 0;
			for (int i = 0; i < N; ++i) {
				if((mask & (1<<i))) sum ^= a[i];
			}
			if(sum == K) cnt++, cnt %= MOD;
		}
		printf("%lld\n", cnt);
		return 0;
	} else {
		dp[0][0] = 1;
		rep(i, N)rep(j, 520) {
			// printf("i %d j %d %d\n", i, j, dp[i][j]);
			if(dp[i][j] == 0) continue;
			if((j ^ a[i]) > 520) continue;
			// printf("%d %d %d\n", i, j, j ^ a[i]);
			(dp[i + 1][j ^ a[i]] += dp[i][j]) %= MOD;
			// printf("%d\n", dp[i + 1][j ^ a[i]]);
			(dp[i + 1][j] += dp[i][j]) %= MOD;
		}
		printf("%lld\n", dp[N][K] % MOD);
 
 
		/*
		vector<int> v;
		rep(i, N) if(a[i] < 100) {
			v.pb(a[i]);
		}
		int n = v.size();
 
		rep(i, n)rep(j, )
	*/
		return 0;
	}
	return 0;
}