#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_V = 20000;

struct Flow{
	struct edge{
		int to, cap, rev;
	};
	vector<edge> G[MAX_V];//隣接リスト
	bool used[MAX_V];

	void add_edge(int from, int to, int cap){
		G[from].push_back((edge){to, cap, G[to].size()});//from -> to
		G[to].push_back((edge){from, 0, G[from].size() - 1});//to -> from
	}

	//増加パスを探す
	int dfs(int v, int t, int f){
		if(v == t) return f;
		used[v] = true;
		for (int i = 0; i < G[v].size(); ++i){
			edge &e = G[v][i];
			if(!used[e.to] && e.cap > 0){
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	//sからtへの最大流
	int max_flow(int s, int t){
		int flow = 0;
		while(1){
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, INF);
			if(f == 0) return flow;
			flow += f;
		}
	}
};

int j[10010], c[10010];
set<int> x[55];
int main(void){
	int w; cin >> w;
	int n; cin >> n;
	rep(i, n) cin >> j[i];
	int m; cin >> m;
	rep(i, m) cin >> c[i];
	rep(i, m){
		int q; cin >> q;
		rep(j, q){
			int tmp; cin >> tmp;
			tmp--;
			x[i].insert(tmp);
		}
	}
	Flow mf;
	//s = 0; t = 200
	rep(i, n) mf.add_edge(0, i + 1, j[i]);//s -> 作画
	rep(i, m) mf.add_edge(100 + i, 200, c[i]);//監督 -> t
	rep(v, m){
		rep(u, n){
			if(x[v].count(u) == 0){//u -> vが許される
				mf.add_edge(u + 1, v + 100, INF);
			}
		}
	}

	ll ans = mf.max_flow(0, 200);
	if(ans >= w) printf("SHIROBAKO\n");
	else printf("BANSAKUTSUKITA\n");
	return 0;
}