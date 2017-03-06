#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

class DisjointSet{
    public:
        vector<int> rank, p;//rank:木の高さ p:親の頂点番号
        DisjointSet(){}
        DisjointSet(int size){//頂点の数
            rank.resize(size, 0);
            p.resize(size, 0);
            rep(i, size) makeSet(i);
        }
        void makeSet(int x){
            p[x] = x;
            rank[x] = 0;
        }
        bool same(int x, int y){return findSet(x) == findSet(y);}
        void unite(int x, int y){link(findSet(x), findSet(y));}
        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

vector<int> g[200010], ans;
int main(void){
	int n, m, s; cin >> n >> m >> s;
	s--;
	rep(i, m){
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	DisjointSet uf(n);
	//逆からunion-find
	//i番目の頂点に到達できるか考える時は、iより大きい頂点だけで作られる、グラフを作り、
	//sとiから同じ連結成分に含まれるかを調べればいい。
	for (int i = n - 1; i >= 0; --i){
		for(auto j : g[i]){
			if(j >= i){//iより大きい頂点と繋がっている道は追加
				uf.unite(i, j);
			}
		}
		if(uf.same(s, i)) ans.push_back(i);
	}
	reverse(ans.begin(), ans.end());
	rep(i, ans.size()){
		cout << ans[i] + 1 << endl;
	}
	return 0;
}