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
ll A, B;
vector<ll> H;

bool hantei() {
	ll sum = 0;
	reps(i, A, N) sum += H[i];
	// printf("sum %lld\n", sum);
	if(B - A >= sum) return true;
	else return false;
}

bool solve(ll k) {
	ll nA = A;
	vector<ll> nokori;
	rep(i, N) {
		if(nA > 0) {
			ll t = H[i] / k;
			if(t <= nA) {
				nokori.pb(H[i] - k * t);
				nA -= t;
			}else{
				nokori.pb(H[i] - k * nA);
				nA = 0;
			}
		}else {
			nokori.pb(H[i]);
		}
	}
	sort(all(nokori)); reverse(all(nokori));
	/*
	printf("\n");
	for(auto u : nokori) printf("%lld ", u);
	printf("\n");
	*/
	ll sum = 0;
	reps(i, nA, N) sum += nokori[i];
	if(B - A >= sum) return true;
	else return false;
}

int main(void) {
	cin >> N;
	cin >> A >> B;
	rep(i, N) {
		ll t; cin >> t;
		H.pb(t);
	}
	sort(all(H)); reverse(all(H));
	if(!hantei()) {
		printf("-1\n"); return 0;
	}
	// printf("k\n");
	ll l = 1, r = INF + 1;
	while(r - l > 2)  {
		ll m = (l + r) / 2;
		// printf("m %lld\n", m);
		if(solve(m)) r = m;
		else l = m;
	}
	for (ll i = max<ll>(1, l - 100ll); i < min<ll>(INF, r + 100ll); ++i) {
		if(solve(i)) {
			printf("%lld\n", i); return 0;
		}
	}
	return 0;
}