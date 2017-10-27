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

int main(void) {
	cin >> N;
	ll ans = 0;
	rep(i, N) {
		int X, Y, Z;
		int M;
		int x[110], y[110], z[110];
		cin >> X >> Y >> Z;
		cin >> M;
		rep(j, M) cin >> x[j] >> y[j] >> z[j];
		int minx = INF, miny = INF, minz = INF;
		int maxx = 0, maxy = 0, maxz = 0;
		rep(j, M) chmin(minx, x[j]), chmin(miny, y[j]), chmin(minz, z[j]);
		rep(j, M) chmax(maxx, x[j]), chmax(maxy, y[j]), chmax(maxz, z[j]);
		// printf("%d %d %d %d %d %d\n", minx, miny, minz, maxx, maxy, maxz);
		// 一つの豆腐を6つに分けて考える 幅の分が石の数として考えれる
		ans ^= minx, ans ^= miny, ans ^= minz;
		ans ^= (X - maxx - 1), ans ^= (Y - maxy - 1), ans ^= (Z - maxz - 1);
	}
	if(ans == 0)printf("LOSE\n");
	else printf("WIN\n");
	return 0;
}