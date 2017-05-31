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

int T;
int n, m;
int a[510][510];

void solve() {
	scanf("%d %d", &n, &m);
	rep(i,n)rep(j,m)scanf("%d", &a[i][j]);
	int ma = 0;
	rep(i, n)rep(j, m) chmax(ma, a[i][j]);
	queue<pair<pair<int, int>, int>> q;
	rep(i, n)rep(j, m) if(a[i][j] == ma) q.push(make_pair(make_pair(i, j), 1));
	static const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int ans = 0;
	while(!q.empty()) {
		auto d = q.front(); q.pop();
		int y = d.fi.fi, x = d.fi.se, cnt = d.se;
		// printf("%d %d %d\n", y, x, cnt);
		rep(k, 8){
			int ny = y + dy[k], nx = x + dx[k];
			if(!(0 <= ny && ny < n && 0 <= nx && nx < m)) continue;
			if(a[ny][nx] != a[y][x]){
				a[ny][nx] = a[y][x];
				chmax(ans, cnt);
				q.push(make_pair(make_pair(ny, nx), cnt + 1));
			}
		}
	}
	printf("%d\n", ans);
}


int main(void){
	scanf("%d", &T);
	while(T--){
		solve();
	}
}