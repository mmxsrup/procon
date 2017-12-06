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

int N, T;
int a[10], b[10];
int c[110][10], d[110][10];
int y[110][10], x[110][10];

int dist(int y1, int x1, int y2, int x2) {
	return abs(y1 - y2) + abs(x1 - x2);
}

int main(void) {
	cin >> N >> T;
	rep(i, N) cin >> a[i] >> b[i];
	rep(i, T)rep(j, N) cin >> c[i][j] >> d[i][j];

	rep(i, N) y[0][i] = a[i], x[0][i] = b[i];
	rep(i, T) rep(j, N) y[i + 1][j] = c[i][j], x[i + 1][j] = d[i][j];

	int ans = 0;
	rep(k, T) {
		vector<int> v;
		rep(i, N) v.pb(i);
	    int tans = INF;
	  	do {
	  		int tmp = 0;
	        rep(i, N) tmp += dist(y[k][i], x[k][i], y[k + 1][v[i]], x[k + 1][v[i]]);
	        tans = min(tans, tmp);
	        // printf("tans %d\n", tans);
	    }while( next_permutation(v.begin(), v.end()) );
	    ans += tans;
	}
	printf("%d\n", ans);
	return 0;
}