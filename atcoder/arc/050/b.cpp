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
const int INF = 1e9;
#define int long long
ll r, b, x, y;

ll cul(ll t){// t := 赤がx本で青が1本の花束の数
	ll R = r, B = b;
	R -= x * t;
	B -= 1 * t;
	if(R < 0 || B < 0) return 0;
	return t + min(R, B / y);
}

signed main(void){
	cin >> r >> b >> x >> y;
	ll left = -1, right = min(r / x, b);

	while(right - left > 10){
		// printf("%lld %lld\n", l, r);
		ll mid1 = (left * 2 + right) / 3;
		ll mid2 = (left + right * 2) / 3;
		ll ret1 = cul(mid1);
		ll ret2 = cul(mid2);
		if(ret1 < ret2) left = mid1;
		else right = mid2;
	}
	ll ans = 0;
	for (ll i = max(0ll, left - 100); i < min(r / x, right + 100) + 1; ++i){
		// printf("%lld\n", i);
		chmax(ans, cul(i));
	}
	printf("%lld\n", ans);
	return 0;
}