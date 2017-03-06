#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pairt
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

//ダイクストラ法を用いた、最短経路とその経路を求めるライブラリ
const int INF = 1e9;
const int MAX_V = 210;//頂点の数
int cost[MAX_V][MAX_V];//cost[u][v]は辺e=(u, v)のコスト(存在しない場合はINF)
int d[MAX_V];//頂点sからの最短距離
bool used[MAX_V];//すでに使われたかどうかのフラグ
int V;//頂点数
int prv[MAX_V];//最短路の直前の頂点

int s, g;

//始点sから各頂点への最短経路を求める
void dijkstra(int s){//始点を引数に
	//初期化
	fill(d, d + V, INF);
	fill(used, used + V, false);
	fill(prv, prv + V, -1);
	d[s] = 0;

	while(true){
		int v = -1;
		//まだ使われてない頂点の内、距離が最小のものを選ぶ
		for(int u = 0; u < V; u++){
			if(!used[u] && (v == -1 || d[u] < d[v])) v = u;
		}

		if(v == -1) break;
		used[v] = true;

		for(int u = 0; u < V; u++){
			if(d[u] > d[v] + cost[v][u]){
				d[u] = d[v] + cost[v][u];
				prv[u] = v;
			}
			//最短経路を復元する必要がない場合
			//d[u] = min(d[u], d[v] + cost[v][u]);
		}
	}
	return;	
}

//頂点tへの最短路
vector<int> get_path(int t){//引数でゴールを渡す
	prv[s] = -1;
	vector<int> path;
	for(; t != -1; t = prv[t]){
		printf("t: %d\n", t);
		path.push_back(t);//tがsになるまで、prv[t]を巡っていく
	}
	//このままだと、t->sの順位なっているので、逆順にする
	reverse(path.begin(), path.end());
	return path;
}

int main(void){
	int n, m;
	scanf("%d%d%d%d", &n, &m, &s, &g);
	//大きめの数字で初期化
	rep(i, 210)rep(j, 210) cost[i][j] = cost[j][i] = INF;
	//同じ時点は0
	rep(i, 210) cost[i][i] = 0;
	//入力
	rep(i, m){
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		//a--; b--; //0オリジンへ
		cost[a][b] = cost[b][a] = c;//無向グラグ　2つに代入すること
	}

	dijkstra(s);
	vector<int> ans = get_path(g);
	int size = ans.size();
	rep(i, size) printf("%d ", ans[i]);
	printf("\n");

	return 0;		
}

