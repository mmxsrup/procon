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

int dist(int x1, int y1, int x2, int y2){
	return abs(x1 - x2) + abs(y1 - y2);
}
int func(int i, int j, int x1, int y1, int x2, int y2) {
	// printf("%d %d %d %d %d %d\n", i, j, x1, y1, x2, y2);
	int ret = INF;
	if(x1 == x2){
		for (int k = min(y1, y2); k <= max(y1, y2); ++k) {
			chmin(ret, dist(i, j, x1, k));
		}
	}else if(y1 == y2) {
		for (int k = min(x1, x2); k <= max(x1, x2); ++k) {
			chmin(ret, dist(i, j, k, y1));
		}
	}
	return ret;
}

void solve() {
	int n;
	int x1[55], y1[55], x2[55], y2[55];
	scanf("%d", &n);
	rep(i, n) scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
	int ans = INF;
	for (int i = 0; i <= 50; ++i){ // x
		for (int j = 0; j <= 50; ++j){ // y
			int tmp = 0;
			for (int k = 0; k < n; ++k){
				chmax(tmp, func(i, j, x1[k], y1[k], x2[k], y2[k]));
			}
			// printf("i %d j %d %d\n", i, j, tmp);
			chmin(ans, tmp);
		}
	}
	printf("%d\n", ans);
}
int main(void){
	int T; cin >> T;
	while(T--){
		solve();
	}
}