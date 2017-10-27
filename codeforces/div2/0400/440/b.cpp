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

int n, k;
ll a[100010];

int main(void) {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%lld", &a[i]);

	if(k == 1) {
		ll ans = INFF;
		rep(i, n) chmin(ans, a[i]);
		printf("%lld\n", ans);
	}else if(k == 2) {
		ll ml[100010];
		ll mr[100010];
		ml[0] = a[0];
		reps(i, 1, n) ml[i] = min(ml[i - 1], a[i]);
		mr[n - 1] = a[n - 1];
		for (int i = n - 2; i >= 0; --i) {
			mr[i] = min(mr[i + 1], a[i]);
		}
		ll ans = -INFF;
		rep(i, n - 1) {
			ll tmp = max(ml[i], mr[i + 1]);
			chmax(ans, tmp);
		}
		cout << ans << endl;
	}else {
		ll ans = -INFF;
		rep(i, n) chmax(ans, a[i]);
		printf("%lld\n", ans);
	}
	return 0;
}