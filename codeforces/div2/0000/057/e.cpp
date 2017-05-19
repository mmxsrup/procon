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

int n;
int a[1000100];
multiset<int> l, r;

int main(void){
	cin >> n;
	rep(i, n) cin >> a[i];
	l.insert(a[0]);
	reps(i, 2, n) r.insert(a[i]);

	ll ans = 0;
	reps(i, 1, n - 1){
		auto it1 = l.lower_bound(a[i]);
		auto it2 = r.upper_bound(a[i]);
		int d1 = it1 - l.begin();
		// printf("%d %d\n", d1, d2);
		// ans += d1 * d2;
	}
	printf("%lld\n", ans);
	return 0;
}