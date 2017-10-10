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

int n;
ll A[40], B[40];
vector<ll> solve(vector<pair<ll, ll>> &v) {
	vector<pair<ll, ll>> tmp;
	for (int mask = 0; mask < (1<<v.size()); ++mask) {
		ll a = 0, b = 0;
		rep(i, v.size()) {
			if(mask & (1<<i)) a += v[i].fi;
			else b += v[i].se;
		}
		tmp.pb(mp(a, b));
	}
	vector<ll> ret;
	for(auto u : tmp) ret.pb(u.fi - u.se);
	sort(all(ret));
	return ret;
}

int main(void) {
	cin >> n;
	rep(i, n) cin >> A[i] >> B[i];
	vector<pair<ll, ll>> v1, v2;
	rep(i, n / 2) v1.pb(mp(A[i], B[i]));
	reps(i, n / 2, n) v2.pb(mp(A[i], B[i]));

	auto rv1 = solve(v1), rv2 = solve(v2);

	/*
	for(auto u : rv1) printf("%lld ", u);
	printf("\n");
	for(auto u : rv2) printf("%lld ", u);
	printf("\n");
	*/

	ll ans = INFF;
	for(auto u : rv1) {
		ll aim = -u;
		int idx = lower_bound(all(rv2), aim) - rv2.begin();
		ll tans = min(abs(u + rv2[max(idx - 1, 0)]), 
					min(abs(u + rv2[idx]), abs(u + rv2[min(idx + 1, (int)rv2.size() - 1)])));
		chmin(ans, tans);
	}
	printf("%lld\n", ans);
	return 0;
}