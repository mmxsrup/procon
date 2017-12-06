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
ll dp[100010][300];

int main(void) {
	cin >> N >> K;
	rep(i, N) cin >> a[i];

	ll cnt = 0;
	if(N <= 24) {
	// if(N == 0){
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
		
		ll ans = 0;

		vector<int> v, big;
		rep(i, N){
			if(a[i] < 100) v.pb(a[i]);
			else big.pb(a[i]);
		}
		int bn = big.size();
		int n = v.size();
		// printf("%d %d\n", bn, n);
		dp[0][0] = 1;
		rep(i, n)rep(j, 220) {
			if(dp[i][j] == 0) continue;
			if((j ^ v[i]) > 220) continue;
			(dp[i + 1][j ^ v[i]] += dp[i][j]) %= MOD;
			(dp[i + 1][j] += dp[i][j]) %= MOD;
		}

		// printf("k\n");
		for (int mask = 0; mask < (1<<bn); ++mask) {
			// printf("mask %d\n", mask);
			int sum = 0;
			rep(i, bn) if((mask & (1<<i))) sum ^= big[i];
			// printf("sum %d\n", sum);
			(ans += dp[N][sum ^ K]) %= MOD;
		}
		printf("%lld\n", ans % MOD);
		return 0;
	}
	return 0;
}