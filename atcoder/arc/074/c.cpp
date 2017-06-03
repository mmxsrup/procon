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

int main(void){
	ll H, W; cin >> H >> W;
	if(W % 3 == 0 || H % 3 == 0){
		printf("0\n");
		return 0;
	}

	// if(H > W) swap(H, W);
	ll ans = INFF;
	if(H % 2 == 1 && W % 2 == 1){
		ll h1 = H / 2;
		ll h2 = H - h1;
		ll w1 = W / 2;
		ll w2 = W - w1;
		
		ll sum1 = h1 * w2;
		ll sum2 = h1 * w1;
		ll sum3 = h2 * w2;
		ll sum4 = h2 * w1;
		ll ma1 = max(sum3, max(sum1 + sum2, sum4));
		ll mi1 = min(sum3, min(sum1 + sum2, sum4));
		ll ma2 = max(sum3, max(sum1, sum2 + sum4));
		ll mi2 = min(sum3, min(sum1, sum2 + sum4));
		chmin(ans, abs(ma1  - mi1));
		chmin(ans, abs(ma2 - mi2));
		// printf("%lld\n", ans);
	}else if(H % 2 == 0 && W % 2 == 0){
		// printf("k\n");
		// ll ans = INFF;
		ll sum = H * W;
		// printf("H %lld %lld\n", H, W);
		for (int i = 0; i <= W; ++i){
			ll d = H * i;
			ll d1 = (sum - d) / 2;
			chmin(ans, abs((d1 - d)));
		}
		swap(H, W);
		for (int i = 0; i <= W; ++i){
			ll d = H * i;
			ll d1 = (sum - d) / 2;
			chmin(ans, abs((d1 - d)));
		}
		// printf("%lld\n", ans);
	}else if(H % 2 == 0 || W % 2 == 0){

		if(H % 2) swap(H, W);
		// ll ans = INFF;
		ll sum = H * W;
		for (int i = 0; i <= W; ++i){
			ll d = H * i;
			ll d1 = (sum - d) / 2;
			chmin(ans, abs((d1 - d)));
		}

		swap(H, W);
		for (int i = 0; i <= W; ++i){
			ll d1 = H * i;
			ll w = W - i;
			ll d2 = w * (H / 2);
			ll d3 = w * (H / 2 + 1);
			ll ma = max(d1, max(d2, d3));
			ll mi = min(d1, min(d2, d3));
			chmin(ans, abs(ma - mi));
		}
		// printf("%lld\n", ans);
	}
	// printf("k\n");

	if(H % 3 == 1 || W % 3 == 1){
		if(H % 3 != 1) swap(H, W);
		ll h1 = H / 3;
		ll h2 = H - h1 * 2;
		chmin(ans, abs(W * h2 - W * h1));
	}
	if(H % 3 == 2 || W % 3 == 2){
		if(H % 3 != 2) swap(H, W);
		ll h1 = H / 3;
		ll h2 = (H - h1) / 2;
		chmin(ans, abs(W * h2 - W * h1));
	}
	printf("%lld\n", ans);
	return 0;
}