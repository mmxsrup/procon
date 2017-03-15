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
int x[100010], y[100010];
set<pair<int, int>> se[150][150];

int dist(int x, int y){
	return x * x + y * y;
}
int main(void){
	cin >> n;
	rep(i, n) cin >> x[i] >> y[i];
	int ans = 0;
	rep(i, n){
		// printf("x %d y %d\n", x[i], y[i]);
		int cx = x[i] / 150, cy = y[i] / 150;
		bool flag = true;
		for(auto u : se[cx][cy]){
			int nx = u.fi, ny = u.se;
			auto d = dist(nx - x[i], ny - y[i]);
			// printf("%d %d %d \n", nx, ny, d);
			if(d < 400){
				flag = false;
				break;
			}
		}
		if(flag){
			ans++;
			se[cx][cy].insert(mp(x[i], y[i]));
			se[max(cx - 1, 0)][cy].insert(mp(x[i], y[i]));
			se[cx + 1][cy].insert(mp(x[i], y[i]));
			se[cx][max(cy - 1, 0)].insert(mp(x[i], y[i]));
			se[cx][cy + 1].insert(mp(x[i], y[i]));

			se[max(cx - 1, 0)][max(cy - 1, 0)].insert(mp(x[i], y[i]));
			se[cx + 1][max(cy - 1, 0)].insert(mp(x[i], y[i]));
			se[max(cx - 1, 0)][cy + 1].insert(mp(x[i], y[i]));
			se[cx + 1][cy + 1].insert(mp(x[i], y[i]));
		}
	}
	printf("%d\n", ans);
	return 0;
}