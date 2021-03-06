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

int N;
int x[100100], y[100100];
int Q;
int a[100100], b[100100];

class Tree_lca{
public:
	static const int MAXLOG_V = 25;
	vector<vector<int> > G;
	int V, root;//頂点数 根
	// parent[k][v] := 頂点vから2^k回親側に登って到達する頂点 (通り過ぎると-1)
	vector<int> parent[MAXLOG_V];
	vector<int> depth;//根からの深さ
	
	Tree_lca(int V, int root) : V(V), root(root){
		G.resize(V);
		for (int i = 0; i < MAXLOG_V; ++i) parent[i].resize(V);
		depth.resize(V);
	}
	void unite(int u, int v){ //u-vをunite
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int dist(int u, int v){ // u-v の距離
		int p = lca(u, v);
		return (depth[u] - depth[p]) + (depth[v] - depth[p]);
	}
	void init(){ //parent[0]とdepthを初期化
		dfs(root, -1, 0);
		//parentを初期化 2^kごとのテーブルを作成
		for (int k = 0; k + 1 < MAXLOG_V; ++k){
			for (int v = 0; v < V; ++v){
				if(parent[k][v] < 0) parent[k + 1][v] = -1;//root(rootより上)が親
				else parent[k + 1][v] = parent[k][parent[k][v]];//ダブリングで2倍上の親を求める
			}
		}
	}
private:
	//１つ上の親と深さを設定
	void dfs(int v, int p, int d){//ノード番号　親のノード番号　深さ
		parent[0][v] = p;
		depth[v] = d;
		for(auto u : G[v]){
			if(u != p) dfs(u, v, d + 1);
		}
	}
	//u, vのLCAを求める
	int lca(int u, int v){
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k + 1 < MAXLOG_V; k++){ //uがvと同じ高さになるまで親を辿る
			if (((depth[v] - depth[u]) >> k) & 1) {
				v = parent[k][v];//bitが立っていれば、親を2^k辿っていく
			}
		}
		if (u == v) return u;
		//2分探索でLCAを求める　LCAより上の親(LA)は常に同じになる
		for (int k = MAXLOG_V - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]){//LCAにたどり着く限界まで、上を目指せばいい
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];//1つ上がLCA
	}
};

int main(void) {
	cin >> N;
	rep(i, N - 1) cin >> x[i] >> y[i];
	rep(i, N - 1) x[i]--, y[i]--;
	cin >> Q;
	rep(i, Q) cin >> a[i] >> b[i];
	rep(i, Q) a[i]--, b[i]--;

	Tree_lca lca(N, 0);
	rep(i, N - 1) {
		lca.unite(x[i], y[i]);
	}
	lca.init();
	rep(i, Q) {
		cout << lca.dist(a[i], b[i])  + 1 << endl;
	}
	return 0;
}