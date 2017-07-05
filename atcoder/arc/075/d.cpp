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

ll N, A, B;

bool solve(ll x, vector<ll> &v){
	// printf("x %lld\n", x);
	ll cnt = 0;
	ll C = A - B;
	for(auto u : v) {
		ll d = u - x * B;
		// printf("u %lld d %lld\n", u, d);
		if(d <= 0) continue;
		ll k = d / C + (d % C ? 1 : 0);
		// printf("%lld\n", k);
		cnt += k;
	}
	if(cnt <= x) return true;
	else return false;
}

int main(void) {
	cin >> N >> A >> B;
	vector<ll> h(N);
	rep(i, N){
		cin >> h[i];
	}

	ll l = -1, r = INF;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		if(solve(m, h)) r = m;
		else l = m;
	}
	printf("%lld\n", r);
	return 0;
}