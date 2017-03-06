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

ll inv[1000010];
ll fac[1000010], facInv[1000010];
class MATH{
public:
	void init(void){
		inverse();
		factroial();
	}
	void inverse(void){
		inv[1] = 1;
		for (int i = 2; i <= 1000000; ++i){
			inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
		}
	}
	void factroial(void){
		fac[0] = facInv[0] = 1;
		for (int i = 1; i <= 1000000; ++i){
			fac[i] = (fac[i - 1] * i) % MOD;
			facInv[i] = (facInv[i - 1] * inv[i]) % MOD;
		}
	}
	ll nCr(ll n, ll c){
		ll ret = fac[n];
		(ret *= facInv[c]) %= MOD;
		(ret *= facInv[n - c]) %= MOD;
		return ret;
	}
};


int main(void){
	cin >> m;
	int t, sum = 0;
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

	ll n = h.size() + (m - (sum + h.size() - 1));
	ll k = m - (sum + h.size() - 1);
	MATH mt;
	mt.init();
	// printf("%d %d\n", n, k);
	printf("%lld\n", mt.nCr(n, k) % MOD);
	return 0;
}