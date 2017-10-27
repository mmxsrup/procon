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
ll X;
ll w[40];
ll dp1[(1<<20)], dp2[(1<<20)];

int main(void) {
	cin >> N >> X;
	rep(i, N) cin >> w[i];
	int k1 = N / 2, k2 = N - k1;
	rep(mask, (1<<k1)) {
		ll tmp = 0;
		rep(i, k1) if(mask & (1<<i)) tmp += w[i];
		dp1[mask] = tmp;
	}
	rep(mask, (1<<k2)) {
		ll tmp = 0;
		rep(i, k2) if(mask & (1<<i)) tmp += w[k1 + i];
		dp2[mask] = tmp;
	}

	map<ll, ll> ma1, ma2;
	rep(mask, (1<<k1)) ma1[dp1[mask]]++;
	rep(mask, (1<<k2)) ma2[dp2[mask]]++;
	ll ans = 0;
	for(auto u : ma1) {
		ans += u.se * ma2[X - u.fi];
	}
	cout << ans << endl;
	return 0;
}