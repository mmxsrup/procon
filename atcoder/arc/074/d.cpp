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

#define int long long
int N;
int a[300010];

signed main(void){
	cin >> N;
	rep(i, 3 *N) cin >> a[i];


	ll ans = -INFF;
	ll suml = 0, sumr = 0;

	set<int> l;
	set<pair<int, int>> r1, r2;

	vector<pair<int ,int>> vr;
	rep(i, N) l.insert(a[i]);

	rep(i, N) suml += a[i];

	reps(i, N, 3 * N) vr.pb(mp(a[i], i));
	sort(all(vr));

	rep(i, N) sumr += vr[i].fi;
	rep(i, N) r1.insert(mp(-vr[i].fi, vr[i].se));
	reps(i, N, 2 * N) r2.insert(mp(-vr[i].fi, vr[i].se));


	for (int i = N - 1; i <= 2 * N - 1; ++i){
		// printf("suml %lld sumr %lld\n", suml, sumr);
		chmax(ans, suml - sumr);

		if(*l.begin() < a[i + 1]){
			// printf("a %lld\n", a[i + 1]);
			suml += a[i + 1] - *l.begin();
			l.erase(l.begin());
			l.insert(a[i + 1]);
		}

		if(r1.count(mp(-a[i + 1], i + 1))){
			r1.erase(mp(-a[i + 1], i + 1));
			auto tmp = *r2.begin();
			sumr += -tmp.fi - a[i + 1];
			// printf("2 %lld %lld\n", tmp.fi, a[i + 1]);
			r1.insert(tmp);
		}
	}
	printf("%lld\n", ans);
	return 0;
}