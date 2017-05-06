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
ll H[100010], S[100010];

bool solve(ll lim_h){
	vector<ll> lim_time;
	rep(i, N){
		if(lim_h < H[i]) return false;
		//割り切れなければ, その前までに倒しておかなければならない
		ll time = (lim_h - H[i]) / S[i];
		lim_time.pb(time);
	}
	sort(all(lim_time));
	rep(i, N){
		if(lim_time[i] < i) return false;
	}
	return true;
}

int main(void){
	cin >> N;
	rep(i, N) cin >> H[i] >> S[i];
	ll l = 0, r = INFF; //[l, r)
	while(r - l > 1){
		ll m = (l + r) / 2;
		if(solve(m)) r = m; //もっと低くできる
		else l = m + 1;
	}
	for (ll i = max(0ll, l - 10); i <= min(INFF, r + 10) ; ++i){
		if(solve(i)){
			printf("%lld\n", i);
			return 0;
		}
	}
	return 0;
}