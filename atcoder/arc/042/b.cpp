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

int sx, sy;
int N;
int x[20], y[20];

int main(void){
	cin >> sx >> sy >> N;
	rep(i, N) cin >> x[i] >> y[i];
	double ans = INF;
	rep(i, N){
		int x3 = sx, y3 = sy;
		int x1 = x[i], y1 = y[i];
		int x2 = x[(i + 1) % N], y2 = y[(i + 1) % N];
		int ux = x2 - x1, uy = y2 - y1;
		double vx = x3 - x1, vy = y3 - y1;
		double L = (ux * vy - uy * vx) / (sqrt(ux * ux + uy * uy));
		chmin(ans, L);
	}
	printf("%.9f\n", ans);
	return 0;
}