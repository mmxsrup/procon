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

ll N, M;
ll a[2010], b[2010], c[2010];


signed main(void){
	cin >> N >> M;
	rep(i, M) cin >> a[i] >> b[i] >> c[i];
	rep(i, M) a[i]--, b[i]--;

	vector<long long> d(N, -INFF);
	d[0] = 0;
	rep(i, N)rep(j, M){
		chmax(d[b[j]], d[a[j]] + c[j]);
	}
	ll ans1 = d[N - 1];
	rep(j, M){
		chmax(d[b[j]], d[a[j]] + c[j]);
	}
	ll ans2 = d[N - 1];
	if(ans1 != ans2) printf("inf\n");
	else printf("%lld\n", ans1);
	return 0;
}