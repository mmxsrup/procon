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
	/*
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

	*/

	vector<pair<ll, ll> > sch, que;
	vector<pair<ll, ll> >memo;
	memo.pb(mp(-1, 0));
	vector<ll> ret;
	int cnt = 0;
	rep(i, q){
		if(v[i].size() == 2){
			sch.pb(mp(v[i][0], v[i][1]));
		}else{
			que.pb(mp(v[i][0], cnt));
			cnt++;
		}
	}
	sort(all(sch));
	ll now = 0;
	ll nokori = 0;
	ll ans = 0;
	rep(i, sch.size()){
		nokori += (sch[i].fi - now) * k;
		now = sch[i].fi;
		ans += min(nokori, sch[i].se);
		memo.pb(mp(sch[i].fi, ans));
	}
	sort(all(que));
	ret.resize(que.size());

	int idx = 0;
	printf("shc\n");
	rep(i, sch.size()){
		printf("%d %d\n",sch[i].fi, sch[i].se);
	}
	printf("mem\n");
	rep(i, memo.size()){
		printf("%d %d\n",memo[i].fi, memo[i].se);
	}
	rep(i, que.size()){
		while(memo[idx].fi < que[i].fi)idx++;
		if(idx > memo.size()) idx = memo.size();
		ret[que[i].se] = memo[idx - 1].se;
	}

	for(auto u : ret){
		printf("%lld\n", u);
	}
	return 0;
}