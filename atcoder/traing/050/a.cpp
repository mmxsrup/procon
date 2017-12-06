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

ll H, W, T;
string s[20];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int MAX_N = 1010;
using TYPE = ll; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
vector<TYPE> dijkstra(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(void) {
	cin >> H >> W >> T;
	rep(i, H) cin >> s[i];
	int sx, sy, gx, gy;
	rep(i, H)rep(j, W) {
		if(s[i][j] == 'S') {
			sy = i, sx = j;
			s[i][j] = '.';
		}else if(s[i][j] == 'G') {
			gy = i, gx = j;
			s[i][j] = '.';
		}
	}

	ll l = 0, r = INF + 1;
	while(r - l > 1) {
		ll mid = (l + r) / 2;
		// printf("mid %lld %lld %lld	\n", mid, l, r);
		rep(i, MAX_N) G[i].clear();
		rep(i, H)rep(j, W) {
			rep(k, 4) {
				int ny = i + dy[k], nx = j + dx[k];
				if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;
				if(s[ny][nx] == '.') {
					G[W * i + j].pb(mp(W * ny + nx, 1));
				}else {
					G[W * i + j].pb(mp(W * ny + nx, mid));
				}
			}
		}

		auto dist = dijkstra(W * sy + sx);
		if(dist[W * gy + gx] <= T) l = mid;
		else r = mid;
	}
	printf("%lld\n", l);
	return 0;
}