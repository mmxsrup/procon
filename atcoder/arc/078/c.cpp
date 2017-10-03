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
ll sum[200010];

int main(void) {
	cin >> N;
	rep(i, N) cin >> a[i];
	rep(i, N) sum[i + 1] += a[i] + sum[i];
	ll S = sum[N];
	ll ans = INFF;
	rep(i, N - 1) {
		ll d1 = sum[i + 1], d2 = S - d1;
		chmin(ans, abs(d1 - d2));
	}
	printf("%lld\n", ans);
	return 0;
}