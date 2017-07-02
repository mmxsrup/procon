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

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};
int w, h;
string c[22];
int dist[22][22];

vector<int> G[22];

void solve(pair<int, int> s) {
	rep(i, 22)rep(j, 22) dist[i][j] = INF;
	dist[s.fi][s.se] = 0;
	queue<pair<int, int>> q;
	q.push(mp(s.fi, se.se));
	while(!q.empty()){
		auto y = q.front().fi, x = q.front().se;
		q.pop();
		rep(k, 4) {
			int ny = y + dy[k], nx = x + dx[k];
			if(!(0 <= ny < && ny < h && 0 <= nx && nx < w)) continue;
			if(dist[ny][nx] != INF) continue;
			if(c[ny][nx] == 'x') continue;
			dist[ny][nx] = dist[y][x] + 1;
		}
	}
}

int dp[(1<<22)][22];
void bitdp(void) {
	rep(i, (1<<n))rep(j, n) dp[i][j] = INF;
	dp[0][0] = 0;
	for (int mask = 0; mask < (1<<n); ++mask) {
		for (int u = 0; u < n; ++u) {
			for (auto t : G[u]) {
				auto v = t.fi, cost = t.se;
				if(dp[mask][u] == INF) continue;
				if((mask & (1<<u)) == 0) continue;
				if((mask & (1<<v))) continue;
				chmin(dp[mask | (1<<v)][v], dp[mask][u] + cost);
			}
		}
	}
}
int main(void) {
	while(1) {
		cin >> w >> h;
		if(w == 0 && h == 0) break;
		rep(i, 22) G[i].clear();

		vector<pair<int, int>> gomi;
		rep(y, h)rep(x, w) if(s[y][x] == '*') gomi.pb(mp(y, x));
		for(auto u : gomi) {
			solve(u);
			for(auto v : gomi) {
				G[u].pb(mp(v, dist[u][v]));
			}
		}
	}
	return 0;
}