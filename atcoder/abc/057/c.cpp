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

#define int long long
std::pair<std::vector<ll>, std::vector<ll>> prime_factor_decomp(ll n) {
    std::vector<ll> p, e;
    ll m = n;
    for (ll i = 2; i * i <= n; i++) {
        if (m % i != 0) continue;
        int c = 0;
        while (m % i == 0) c++, m /= i;
        p.push_back(i);
        e.push_back(c);
    }
    if (m > 1) {
        p.push_back(m);
        e.push_back(1);
    }
    return std::make_pair(p, e);
}

signed main(void){
	ll n; cin >> n;
	auto ret = prime_factor_decomp(n);
	auto v = ret.fi, u = ret.se;
	ll a = 1, b = 1;
	for (int i = v.size() - 1; i >= 0; --i){
	// for (int i = 0; i < v.size(); ++i){
		ll x = v[i], k = u[i]; // x^k
		rep(i, k){
			if(a > b) b *= x;
			else a *= x;
		}
		printf("ab %lld %lld\n", a, b);
	}
	string sa = to_string(a), sb = to_string(b);
	// cout << sa << " " << sb << endl;
	auto size = max((int)sa.size(), (int)sb.size());
	cout << size << endl;
	return 0;
}
