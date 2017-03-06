/*
閉路の長さを求める。最小共通祖先(LCA)を利用するといい
LCA -２つの頂点の共通の祖先(親を巡って辿り着ける頂点)
それぞれの頂点について、2^k個前の親を予め計算しておく(テーブルを作る)
テーブルの作り方
	ex)２回親を巡った時に到達する頂点parent2[v]=parent[parent[v]]
	ex)４回親を巡った時に到達する頂点parent4[v]=parent2[parent2[v]](上の情報をつかって)
	parent2^(k+1)[v]=parent2^k[parent2^k[v]] (kが小さい場合から全頂点について逐次計算していけばもとまる)
	ある頂点xの2^(k+1)個前の親 = (xの2^k個前の親)の2^k個前の親
*/

//はむこさん回答を拝借
#include <iostream>
#include <algorithm>
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
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

class Tree_lca {
public:
	//コンストラクタ
    Tree_lca(int V, int root) : V(V), root(root) {
    	//resuze(V)はVの大きさ分メモリ領域を確保することで高速化
        T.resize(V);
        for (int i = 0; i < MAXLOGV; i++) parent[i].resize(V);
        depth.resize(V);
    }

    // uとvをつなぐ
    // lcaを求めることが主目的なので無向グラフとしている
    void unite(int u, int v) {
        T[u].push_back(v);
        T[v].push_back(u);
    }

    // initする
    // コンストラクタだけじゃなくてこれも呼ばないとlcaが求められないぞ
    //dfs+2^k祖先を計算
    void init() {
    	//深さと親を設定
        dfs(root, -1, 0);
        //2^kずつのテーブルを作る
        for (int k = 0; k+1 < MAXLOGV; k++) {
            for (int v = 0; v < V; v++) {
            	//rootより上（存在しないところ）には-1
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                //dpで親を計算していくテーブルを作成
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    // uとvのlcaを求める
    int lca(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < MAXLOGV; k++) {
            if ((depth[v] - depth[u])>>k & 1) {
                v = parent[k][v];
            }
        }
        if (u == v) return u;
        for (int k = MAXLOGV-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // uとvの距離をlcaを利用して求める
    // edgeを定義しないといけない時はこれじゃダメ
    int dist(int u, int v) const {
        int p = lca(u, v);
        //答えはuの深さ + bの深さ - aとbのLCAの深さ + 1
        return (depth[u]-depth[p]) + (depth[v]-depth[p]);
    }

    //深さと親を確認
    void dfs(int v, int p, int d) {//root,-1,0
        parent[0][v] = p;
        depth[v] = d;
        for (int next : T[v]) {
            if (next != p) dfs(next, v, d + 1);
        }
    }

    static const int MAXLOGV = 25;
    // グラフの隣接リスト表現
    vector<vector<int> > T;
    // 頂点の数
    int V;
    // 根ノードの番号
    int root;
 
    // 親ノード
    vector<int> parent[MAXLOGV];
    // 根からの深さ
    vector<int> depth;
};
 
int main(void){
    int n; scanf("%d", &n);

    //頂点の数をn　根ノードの番号を0として呼び出す
    Tree_lca tree(n, 0);
    //uniteする
    rep(i, n - 1){
    	int x, y;
    	scanf("%d %d", &x, &y);
    	x--; y--;//0オリジンに
    	tree.unite(x, y);
    }
  	//inittする
    tree.init();

    int Q; scanf("%d", &Q);
   	rep(i, Q){
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        //答えは
        printf("%d\n", tree.dist(a, b) + 1);
    }
    return 0;
}