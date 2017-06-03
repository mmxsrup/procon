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
int a[200010];

int main(void){
	cin >> N;
	rep(i, N) cin >> a[i];
	set<pair<int, int>> l, r;
	l.insert(mp(INF, -1));
	reps(i, 1, N) r.insert(mp(a[i], i));
	r.insert(mp(INF, N));
	ll ans = 0;
	rep(i, N){
		printf("%d\n", i);
		auto dl = *l.begin();
		auto dr = *r.begin();
		printf("l %d r %d\n", dl.se, dr.se);
		ans += (i - dl.se + 1) * (i - dr.se + 1) * a[i];
		printf("ans %d\n", ans);
		r.erase(r.begin());
		l.insert(mp(i, a[i]));
	}
	printf("%lld\n", ans);
	return 0;
}