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
const ll INFF = 1e18;
 
ll q, k;
vector<ll> v[100010];
int main(void){
	cin >> q >> k;
	rep(i, q){
		int f; cin >> f;
		if(f == 1){
			ll d, a; cin >> d >> a;
			v[i].pb(d), v[i].pb(a);
			
		}else{
			ll d; cin >> d;
			v[i].pb(d);
		}
	}
	vector<pair<ll, ll> > sch;
	vector<ll> ret;
	rep(i, q){
		if(v[i].size() == 2){
			sch.pb(mp(v[i][0], v[i][1]));
		}else{
			ll now = 0;
			ll nokori = 0;
			ll ans = 0;
			sort(all(sch));
			rep(i, sch.size()){
				nokori += (sch[i].fi - now) * k;
				now = sch[i].fi;
				ans += min(nokori, sch[i].se);
			}
			ret.pb(ans);
		}
	}
	for(auto u : ret){
		printf("%lld\n", u);
	}
	return 0;
}