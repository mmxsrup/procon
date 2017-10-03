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

set<int> se;
using tup = tuple<int, int, int>;
vector<pair<int, int> > G[110]; // G[i] := iからG[i].fiまでの距離G[i].se
ll dist[110][110]; // dist[i][j] := 頂点iまで残り時間がjでくる時の最短経路

void dijkstra(int start, int M){
	rep(i, 110)rep(j, 110) dist[i][j] = INFF;
	dist[start][M] = 0;
	priority_queue<tup, vector<tup>, greater<tup>> que; // 距離 頂点 残り時間
	que.push(make_tuple(0, start, M));

	while(!que.empty()){
		int cost, u, nokori;
		tie(cost, u, nokori) = que.top(); que.pop();
		if(dist[u][nokori] < cost) continue;

		for (auto tmp : G[u]){ // u -> v
			int v = tmp.first, time = tmp.second;//隣接する頂点 距離
			int nnokori = nokori - time;
			if(nnokori < 0) continue;
			if(se.count(v)) {
				reps(i, nnokori, M + 1){ // 残り時間をiにする
					int wait = i - nnokori;
					if(dist[v][i] <= dist[u][nokori] + time + wait) continue;
					dist[v][i] = dist[u][nokori] + time + wait;
					que.push(make_tuple(dist[v][i], v, i));
				}
			}else { // 冷凍庫なし
				if(dist[v][nnokori] <= dist[u][nokori] + time) continue;
				dist[v][nnokori] = dist[u][nokori] + time;
				que.push(make_tuple(dist[v][nnokori], v, nnokori));
			}
		}
	}

}


int main(void) {
	while(1) {
		rep(i, 110) G[i].clear();
		se.clear();
		int N, M, L, K, A, H;
		scanf("%d %d %d %d %d %d", &N, &M, &L, &K, &A, &H);
		if(N == 0 && M == 0 & L == 0 && K == 0 && A == 0 && H == 0) break;
		rep(i, L) {
			int l; scanf("%d", &l);
			se.insert(l);
		}
		rep(i, K) {
			int X, Y, T; scanf("%d %d %d", &X, &Y, &T);
			G[X].pb(mp(Y, T)), G[Y].pb(mp(X, T));
		}
		dijkstra(A, M);
		ll ans = INFF;
		rep(i, M + 1) {
			chmin(ans, dist[H][i]);
		}
		if(ans == INFF) printf("Help!\n");
		else printf("%lld\n", ans);
	}
	return 0;
}