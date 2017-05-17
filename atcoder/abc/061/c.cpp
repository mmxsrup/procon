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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

#define int long long 

int N;
ll K;
int a[100010], b[100010];
signed main(void){
	cin >> N >> K;
	rep(i, N) cin >> a[i] >> b[i];
	vector<pair<int, int>> v;
	rep(i, N) v.pb(mp(a[i], b[i]));
	sort(all(v));
	ll now = 0;
	rep(i, N){
		now += v[i].se;
		if(now >= K) {
			printf("%lld\n", v[i].fi);
			return 0;
		}
	}
	return 0;
}