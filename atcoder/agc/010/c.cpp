#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

class Tree_lca{
public:
    Tree_lca(int V, int root) : V(V), root(root){
        G.resize(V);
        for (int i = 0; i < MAXLOG_V; ++i) parent[i].resize(V);
        depth.resize(V);
    }

    //u-vをunite
    void unite(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void init(){
        //parent[0]とdepthを初期化
        dfs(root, -1, 0);
        //parentを初期化 2^kごとのテーブルを作成
        for (int k = 0; k + 1 < MAXLOG_V; ++k){
            for (int v = 0; v < V; ++v){
                if(parent[k][v] < 0) parent[k + 1][v] = -1;//root(rootより上)が親
                else parent[k + 1][v] = parent[k][parent[k][v]];//ダブリングで2倍上の親を求める
            }
        }
    }

    //u, vのLCAを求める
    int lca(int u, int v){
        //uとvが同じ深さになるまで親を辿る
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k + 1 < MAXLOG_V; k++){
            //uがvと同じ高さになるまで親を辿る
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

    //１つ上の親と深さを設定
    void dfs(int v, int p, int d){//ノード番号　親のノード番号　深さ
        parent[0][v] = p;
        depth[v] = d;
        for(auto u : G[v]){
            if(u != p) dfs(u, v, d + 1);
        }
    }

    // uとvの距離をlcaを利用して求める
    int dist(int u, int v){
        int p = lca(u, v);
        //u-vの距離 
        return (depth[u] - depth[p]) + (depth[v] - depth[p]);
    }
    static const int MAXLOG_V = 25;
    vector<vector<int> > G;//隣接リスト
    int V, root;//頂点数と根
    vector<int> parent[MAXLOG_V];//親を2^k辿って到達する頂点(通り過ぎると-1)
    vector<int> depth;//根からの深さ
};


int A[100010];
int s[100010], t[100010];
vector<int> gg[100010];

int main(void){
	int n;	cin >> n;
	rep(i, n) cin >> a[i];
	Tree_lca lca;
	rep(i, n - 1){
		cin >> s[i] >> t[i]; s[i]--; t[i]--;
		
			
	}
	return 0;
}