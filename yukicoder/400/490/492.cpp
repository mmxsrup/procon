#include <bits/stdc++.h>
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
const ll INF = 1e9;
const ll INFF = 1e18;

// x^k (mod m)
long long powmod(long long x, long long k, long long m){
	long long ret = 1;
	while(k){
		if(k & 1) ret = ret * x % m;
		x = x * x % m;
		k >>= 1;
	}
	return ret;
}
// 1/a mod(p(素数))
long long invmod(long long a, long long p){
	return powmod(a, p - 2, p);
}

int main(void){
	ll n; cin >> n;
	ll d = powmod(100, n, MOD) + MOD - 1;
	d %= MOD;
	d *= invmod(99, MOD);
	printf("%lld\n", d % MOD);

	if(n % 11 == 0){
		printf("0\n"); return 0;
	}
	string s = "1";
	n %=11;
	rep(i, n  - 1){
		s = "10" + s;
	}
	cout << s << endl;

	return 0;
}