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
ll L, H;
ll C[20];

ll solve(void) {
	ll ans = 0;
	for (int mask = 1; mask < (1<<N); ++mask) {
		ll cnt =  __builtin_popcount(mask);
		ll lcm = 1;
		rep(i, N) {
			if(mask & (1<<i)) lcm = lcm * C[i] / __gcd(lcm, C[i]);
			if(lcm > H) break;
		}
		// printf("lcm %lld\n", lcm);
		ll tans = (H / lcm) - ((L - 1) / lcm);
		// printf("tans %lld\n", tans);
		if(cnt % 2) ans += tans * cnt;
		else ans -= tans * cnt;
	}
	return ans;
}

int main(void) {
	cin >> N >> L >> H;
	rep(i, N) cin >> C[i];

	printf("%lld\n", solve());
	return 0;
}