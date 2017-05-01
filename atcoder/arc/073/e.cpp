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
ll x[200010], y[200010];

int main(void){
	cin >> N;
	vector<pair<ll, ll> > v;
	rep(i, N) cin >> x[i] >> y[i];
	map<ll, ll> ma;

	rep(i, N){
		if(x[i] > y[i]) swap(x[i], y[i]);
		v.pb(mp(x[i], y[i]));
		if(x[i] == y[i]) ma[x[i]]++;
		else ma[x[i]]++, ma[y[i]]++;
	}
	rep(i, N){
		if(ma[x[i]] >= N){
			printf("0\n");
			return 0;
		}
		if(ma[y[i]] >= N){
			printf("0\n");
			return 0;
		}
	}
	
	sort(all(v));
	ll redmi = INFF, redma = 0;
	ll blumi = INFF, bluma = 0;
	rep(i, N){
		ll s = v[i].fi, t = v[i].se;
		if(i % 2){
			chmin(redmi, s), chmax(redma, s);
			chmin(blumi, t), chmax(bluma, t);
		}else{
			chmin(redmi, t), chmax(redma, t);
			chmin(blumi, s), chmax(bluma, s);
		}
	}
	printf("%lld\n", (redma - redmi) * (bluma - blumi));
	return 0;
}