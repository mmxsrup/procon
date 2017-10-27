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

ll n;
ll A, B;

//x^k mod
long long powmod(long long x, long long k, long long m){ // 繰り返し二乗法(logk)
	if(k == 0) return 1;
	if(k % 2 == 0) return powmod(x * x % m, k / 2, m);
	else return x * powmod(x, k - 1, m) % m;
}

int main(void) {
	cin >> n >> A >> B;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	if(A == 1) {
		sort(all(a));
		rep(i, n) printf("%lld\n", a[i]);
		return 0;
	}

	ll cnt = B;
	sort(all(a))
	while(1) {
		a[0] *= A;
		sort(all(a));
		cnt--;
		if(a[0] * A > a[n - 1]) break;
		if(cnt == 0) break;
	}

	rep(i, cnt % n) a[i] *= A;
	sort(all(a));
	rep(i, n) {
		ll d = cnt / n;
		// printf("d %lld cnt/n %lld v %lld\n", d, cnt/n, v[i]);
		ll ans = powmod(A, d, MOD) * (a[i] % MOD) % MOD;
		printf("%lld\n", ans);
	}
	return 0;
}