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

int main(void) {
	cin >> N;
	vector<int> a(N), b(N), c(N);
	rep(i, N) cin >> a[i];
	rep(i, N) cin >> b[i];
	rep(i, N) cin >> c[i];
	sort(all(a)), sort(all(b)), sort(all(c));
	ll ans = 0;
	rep(i, N) {
		// printf("b %d\n", b[i]);
		ll l = lower_bound(all(a), b[i]) - a.begin();
		ll r = N - (upper_bound(all(c), b[i]) - c.begin());
		// printf("%d %d %d\n", l, r, lower_bound(all(a), b[i]) - a.begin());
		ans += l * r;
	}
	printf("%lld\n", ans);
	return 0;
}