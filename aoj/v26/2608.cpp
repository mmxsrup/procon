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

const int MAX_N = 100010;
vector<pair<int, int> > G[MAX_N];
vector<int> dijkstra(int start){
	vector<int> dist(MAX_N, INF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		int cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; int time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int N, M, s, t;
int x[300010], y[300010];
set<int> dists[100010], distg[100010];

int main(void){
	scanf("%d %d %d %d", &N, &M, &s, &t);
	s--, t--;
	rep(i, M) scanf("%d %d", &x[i], &y[i]);
	rep(i, M) x[i]--, y[i]--;
	rep(i, M) G[x[i]].pb(mp(y[i], 1)), G[y[i]].pb(mp(x[i], 1));
	auto start = dijkstra(s);
	auto goal  = dijkstra(t);

	rep(i, N) if(start[i] != INF) dists[start[i]].insert(i);
	rep(i, N) if(goal[i]  != INF) distg[goal[i]].insert(i);
	// set<pair<int, int> > ans;
	ll ans = 0;
	int len = start[t];
	// printf("len %d\n", len);
	rep(i, len - 1){
		int d1 = i;
		int d2 = (len - 2) - i;
		// printf("d1 %d d2 %d\n", d1, d2);
		for(auto u : dists[d1]){ // s -> u の 距離 d1
			// u と vが異なればいい
			if(distg[d2].count(u) == 0) ans += distg[d2].size();
			else ans += distg[d2].size() - 1;
			/*
			for(auto v : distg[d2]){
				// printf("%d %d\n", u, v);
				if(u != v) ans.insert(mp(min(u, v), max(u, v)));
			}
			*/
		}
	}
	// printf("%d\n", (int)ans.size());
	printf("%lld\n", ans);
	return 0;
}