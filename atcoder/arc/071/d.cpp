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


ll n, m;
ll x[100010], y[100010];
ll a[100010], b[100010];
int main(void){
	cin >> n >> m;
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	// rep(i, n - 1) a[i] = x[i + 1] - x[i];
	// rep(i, m - 1) b[i] = y[i + 1] - y[i];

	ll sumx = 0, sumy = 0;
	rep(i, n) sumx += (i * x[i]) - ((n - 1 - i) * x[i]), sumx %= MOD;
	// printf("x %lld\n", sumx);
	rep(i, m) sumy += (i * y[i]) - ((m - 1 - i) * y[i]), sumy %= MOD;
	// printf("y %lld\n", sumy);
	
	ll ret = sumx * sumy % MOD;
	printf("%lld\n", ret);
	return 0;
}