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

const int MAX_V = 2100;
int V; //頂点数
struct edge { int to, cap, cost, rev; };
vector<edge> G[MAX_V];
int dist[MAX_V]; //最短距離
int prevv[MAX_V], preve[MAX_V];
void add_edge(int from, int to, int cap, int cost) { // from->toへの容量cap,コストcostの辺を追加
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size() - 1});
}
// sからtへの流量fの最小費用流を求める 流せない場合は-1
int min_cost_flow(int s, int t, int f) {
	int res = 0;
	while(f > 0) {
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while(update) {
			update = false;
			for (int v = 0; v < V; ++v){
				if(dist[v] == INF)continue;
				for (int i = 0; i < G[v].size(); ++i){
					edge &e = G[v][i];
					if(e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		if(dist[t] == INF) return -1;

		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge &e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

int main(void) {
	while(1) {
		int n; scanf("%d", &n);
		if(n == 0) break;
		int start = 2 * n, goal = 2 * n + 1;
		int l[1010], r[1010], w[1010];
		rep(i, n) scanf("%d %d %d", &l[i], &r[i], &w[i]);
		rep(i, MAX_V) G[i].clear();

	
		rep(i, n) add_edge(start, 2 * i, 1, 0);
		rep(i, n) add_edge(2 * i + 1, goal, 1, 0);
		rep(i, n) add_edge(2 * i, 2 * i + 1, 1, -w[i]);
		rep(i, n)rep(j, n){
			if(i == j) continue;
			if(r[i] < l[j]) add_edge(2 * i + 1, 2 * j, 1, 0);
		}
		// printf("k\n");
		V = 2 * n + 2;
	

		/*
		rep(i, 365) add_edge(i, i + 1, 2, 0);
		rep(i, n) add_edge(l[i] - 1, r[i], 1, -w[i]);
		V = 366;
		int re = min_cost_flow(0, 365, 2);
		printf("%d\n", -re);
		*/
		
		int ret = min_cost_flow(start, goal, 2);
		printf("%d\n", -ret);
		
	}
	return 0;
}