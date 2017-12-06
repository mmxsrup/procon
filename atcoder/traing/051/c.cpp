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
ll a[100010];
ll ans[100010];

int main(void) {
	cin >> N;
	rep(i, N) cin >> a[i];
	set<ll> se;
	rep(i, N) se.insert(a[i]);
	/*
	ll ma = 0, maidx;
	rep(i, N) {
		if(ma < a[i]) ma = a[i], maidx = i;
	}
	*/

	// map<ll, vector<int>> ma;
	map<ll, pair<int, int>> ma; // ma[i] := 石の数がiのものの中で最小のidxがi, そのような山の数がse
	// rep(i, N) ma[a[i]].pb(i);
	
	rep(i, N) {
		if(ma.count(a[i]) == 0) ma[a[i]].fi = i, ma[a[i]].se = 1;
		else ma[a[i]].se++;
	}
	/*
	for(auto u : ma) {
		cout << u.fi << " " << u.se.fi << " " << u.se.se << endl;
	}
	*/

	vector<int> v;
	for(auto u : se) v.pb(u);
	sort(all(v)); reverse(all(v));
	rep(i, v.size()) {
		// printf("i %d\n", i);
		ll now = v[i], next = v[i + 1];
		ll sa = now - next;
		// sort(all(ma[now]));
		// ans[ma[now].front()] += sa * ma[now].size();
		ans[ma[now].fi] += sa * ma[now].se; //　答えを加える

		// for(auto u : ma[now]) ma[next].pb(u);
		chmin(ma[next].fi, ma[now].fi);
		ma[next].se += ma[now].se;
		// ma[now].clear();
		ma[now].se = ma[now].se = 0;
		/*
		printf("\n");
		for(auto u : ma) {
			cout << u.fi << " " << u.se.fi << " " << u.se.se << endl;
		}
		printf("\n");
		*/
	}
	// ans[0] += N;
	rep(i, N) {
		printf("%lld\n", ans[i]);
	}

	return 0;
}