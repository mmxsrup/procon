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

//x^k mod
long long powmod(long long x, long long k, long long m){ // 繰り返し二乗法(logk)
	if(k == 0) return 1;
	if(k % 2 == 0) return powmod(x * x % m, k / 2, m);
	else return x * powmod(x, k - 1, m) % m;
}

ll n, m;
ll x[100010], y[100010];
int main(void){
	cin >> n >> m;
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	ll ans = ((x[n - 1] - x[0]) % MOD) * ((y[m - 1] - y[0]) % MOD);
	ans %= MOD;
	ll num = (powmod(2, n - 2, MOD) % MOD) * (powmod(2, m - 2, MOD) % MOD);
	num %= MOD;
	ll ret = ans * num;
	ret %= MOD;
	printf("%lld\n", ret);
	return 0;
}