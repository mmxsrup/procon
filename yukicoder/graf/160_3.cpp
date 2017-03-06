#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define mp make_pairt
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

const int INF = 1e9;
struct edge{ int to, cost; };
typedef pair<int, int> P; //firstは経路　secondは頂点の番号

const int MAX_V = 200;//maxの頂点数
int V;//頂点数
vector<edge> G[MAX_V];//0オリジンで代入していくこと
int d[MAX_V];//頂点sからの最短距離
//経路復元用
int pre[MAX_V];//最短路の直前の頂点

void dijkstra(int s){
	// greater<P>を指定することで、firstが小さい順に取り出せるようにする。
	priority_queue<P, vector<P>, greater<P> > que;
	fill(d, d + V, INF);
	d[s] = 0;
	que.push(P(0, s));
	//経路服復元用
	fill(pre, pre + V, -1);

	while(!que.empty()){
		P p = que.top(); que.pop();
		int v = p.second;
		if(d[v] == p.first) continue;
		for (int i = 0; i < G[v].size(); ++i){
			edge e = G[v][i];
			if(d[e.to] > d[v] + e.cost){
				d[e.to] = d[v] + e.cost;
				pre[e.to] = v;//経路復元用
				que.push(P(d[e.to], e.to));
			}
			//経路復元用
			if(d[e.to] == d[v] + e.cost){
				if (v < pre[e.to]) pre[e.to] = v;
			}
		}
	}
}

//頂点tへの最短路
vector<int> get_path(int t){//引数でゴールを渡す
	vector<int> path;
	for(; t != -1; t = pre[t]) path.push_back(t);//tがsになるまで、pre[t]を巡っていく
	//このままだと、t->sの順位なっているので、逆順にする
	reverse(path.begin(), path.end());
	return path;
}

int main(void){
	int n, m, s, g;
	scanf("%d%d%d%d", &n, &m, &s, &g);
	//入力
	rep(i, m){
		//すでに0オリジン
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		//無向グラグ　2つに代入すること
		G[a].push_back(edge{b, c});
		G[b].push_back(edge{a, c});

	}

	dijkstra(s);
	vector<int> ans = get_path(g);
	int size = ans.size();
	rep(i, size) printf("%d ", ans[i]);
	printf("\n");

	return 0;		
}