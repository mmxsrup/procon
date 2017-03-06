#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
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

int m;
vector<int> h;
class MATH{
public:
	ll powmod (ll a, ll p) {
		ll ans = 1;
		ll mul = a;
		for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
			if ((p & 1) == 1) ans = (ans * mul) % MOD;
		}
		return ans;
	}

	ll inverse(ll x) {
		return powmod(x, MOD - 2);
	}

	ll nCr(ll n, ll k) {
	    ll ret = 1;
	    for (ll i = n; i > n - k; i--) {
	        (ret *= i) %= MOD;
	    }
	    for (ll i = k; i >= 1; i--) {
	        (ret *= inverse(i)) %= MOD;
	    }
	    return ret;
	}
};


int main(void){
	cin >> m;
	int t, sum = 0;
	MATH math;
	while(cin >> t){
		h.pb(t);
		sum += t;
	}

	if(h[0] == 0 || h[0] == m){
		printf("1\n");
		return 0;
	}
	if(h.size() + sum - 1 > m){
		printf("NA\n");
		return 0;
	}

	int n = h.size() + (m - (sum + h.size() - 1));
	int k = m - (sum + h.size() - 1);
	// printf("%d %d\n", n, k);
	printf("%lld\n", math.nCr(n, k) % MOD);
	return 0;
}