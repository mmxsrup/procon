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

int n, m;
ll x, a, p;
ll memo[1010][1010];
ll limit[1010];

int main(void) {
	cin >> n >> m;
	cin >> x >> a >> p;
	vector<int> v(n * m);
	rep(i, n)rep(j, n) {
		memo[i][j] = (x + a) % p;
		x = memo[i][j];
		v.push_back(memo[i][j]);
	}
	sort(all(v));
	rep(i, n * m) {
		if(i % m == m - 1) limit[i / m] = v[i];
	}
	rep(i, n) {
		vector<int> no;
		int l = v[i], r = v[i + 1];
		rep(j, m) if(!(l <= ))
	}
	return 0;
}