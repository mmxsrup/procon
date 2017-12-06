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


const int MAX_N = 20000;
ll inv[MAX_N + 10];
ll fac[MAX_N + 10], facInv[MAX_N + 10];
class MATH{
public:
	MATH(){
		inverse();
		factroial();
	}
	ll nCk(ll n, ll k){// n! / k!*(n-k)!
		if(k < 0 || k > n) return 0;
		ll ret = fac[n];
		(ret *= facInv[k]) %= MOD;
		(ret *= facInv[n - k]) %= MOD;
		return ret;
	}
	ll nHk(ll n, ll k){// nHk = n+k-1 C k = (n+k-1)! / k! * (n-1)!
		if(n == 0 && k == 0) return 1;
		ll ret = fac[n + k - 1];
		(ret *= facInv[k]) %= MOD;
		(ret *= facInv[n - 1]) %= MOD;
		return ret;
	}
	ll nPk(ll n, ll k){//nPk = n! / (n-k)!
		if(k < 0 || k > n) return 0;
		ll ret = fac[n];
		(ret *= facInv[n - k]) %= MOD;
		return ret;
	}
private:
	void inverse(void){
		inv[1] = 1;
		for (int i = 2; i <= MAX_N; ++i){
			// inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
			inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		}
	}
	void factroial(void){
		fac[0] = facInv[0] = 1;
		for (int i = 1; i <= MAX_N; ++i){
			fac[i] = (fac[i - 1] * i) % MOD;
			facInv[i] = (facInv[i - 1] * inv[i]) % MOD;
		}
	}
};


int N;
ll A[2010];

int main(void) {
	cin >> N;
	rep(i, N) cin >> A[i];
	set<pair<ll, ll>> se;
	rep(i, N - 1) {
		if(A[i] != -1 && A[i + 1] == -1) {
			se.insert(mp(i, A[i]));
		} else if(A[i] == -1 && A[i + 1] != -1) {
			se.insert(mp(i + 1, A[i + 1]));
		}
	}
	vector<pair<ll, ll>> v;
	for(auto u : se) v.pb(u);
	ll ans = 1;	
	MATH mt;
	rep(i, (int)v.size() - 1) {
		ll n = (v[i + 1].se - v[i].se + 1);
		ll k = (v[i + 1].fi - v[i].fi - 1);
		printf("%lld %lld\n", n, k);
		// nHk
		ll c = 1;
		for (ll j = n + k - 1; j >= n; --j) {
			(c *= j) %= MOD;	
		}
		(c *= facInv[k]) %= MOD;
		printf("%lld\n", c);
		(ans *= c) %= MOD;
	}
	int idx = 0, pidx;
	bool flag = false;
	while(idx < N) {
		if(flag) { // 左端が決まってる
			while(A[idx] == -1) idx++;
			ll n = A[idx] - B[pidx] + 1;
			ll k = idx - pidx - 1

			printf("%lld %lld\n", n, k);
			// nHk
			ll c = 1;
			for (ll j = n + k - 1; j >= n; --j) {
				(c *= j) %= MOD;	
			}
			(c *= facInv[k]) %= MOD;
			printf("%lld\n", c);
			(ans *= c) %= MOD;

			pidx = p;
			flag = false;
		}else{
			if(A[i] != -1) prev = A[i];
			else flag = true;
		}
	}
	printf("%lld\n", ans % MOD);
	return 0;
}