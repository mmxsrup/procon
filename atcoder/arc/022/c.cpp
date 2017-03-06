#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
static const int MAX = 100000;
static const int INF = 1e9;
 
class Edge{
public:
	int t, w;
	Edge(){}
	Edge(int t, int w): t(t), w(w){}
};
 
vector<Edge> G[MAX];
int n, d[MAX];//頂点数
 
bool vis[MAX];
int cnt;
 
void bfs(int s){
	for (int i = 0; i < n; ++i) d[i] = INF;
	queue<int> Q;
	Q.push(s);
	d[s] = 0;
	int u;
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		for (int i = 0; i < G[u].size(); ++i){
			Edge e = G[u][i];
			if(d[e.t] == INF){
				d[e.t] = d[u] + e.w;
				Q.push(e.t);
			}
		}
	}
}
 
int tgt1, tgt2; 
void solve(){
	//適当な視点sから最も遠い節点tgtを求める
	bfs(0);
	int maxv = 0;
	tgt1 = 0;
	for (int i = 0; i < n; ++i){
		if(d[i] == INF) continue;
		if(maxv < d[i]){
			maxv = d[i];
			tgt1 = i;
		}
	}
	//tgtから最も遠い節点の距離をmaxvを求める
	bfs(tgt1);
	maxv = 0;
	for (int i = 0; i < n; ++i){
		if(d[i] == INF) continue;
		
		if(maxv < d[i]){
			maxv = d[i];
			tgt2 = i;
		}
	}
	printf("%d %d\n", tgt1 + 1, tgt2 + 1);
}
 
int main(void){
	int s, t;
	cin >> n;
	for (int i = 0; i < n - 1; ++i){
		cin >> s >> t;
		s--; t--;
		G[s].push_back(Edge(t, 1));
		G[t].push_back(Edge(s, 1));
	}
	solve();
	return 0;
}