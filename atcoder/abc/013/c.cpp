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

ll N, H;
ll A, B, C, D, E;

int main(void){
	cin >> N >> H;
	cin >> A >> B >> C >> D >> E;
	ll ans = INFF;
	rep(x, N + 1){
		ll l = 0, r = N - x + 1; //[l, r)
		while(r - l > 0){
			ll y = (l + r) / 2;
			ll sum = B * x + D * y + H - E * (N - x - y);
			if(sum > 0) r = y;
			else l = y + 1;
		}
		chmin(ans, A * x + C * l);
	}
	printf("%lld\n", ans);
	return 0;
}