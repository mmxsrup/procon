#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
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
        //同じ木にあるか判定（今回使わない）
        bool same(int x, int y){
            return findSet(x) == findSet(y);
        }
        // 木どうしをくっつける
        void unite(int x, int y){
            link(findSet(x), findSet(y));
        }
        //木の高さを考慮して木どうしをくっつける
        void link(int x, int y){
            if(rank[x] > rank[y]){
                p[y] = x;
            }else{
                p[x] = y;
                if(rank[x] == rank[y]) rank[y]++;
            }
        }
        //親を探す（ルートまで）
        int findSet(int x){
            if(x != p[x]){
                p[x] = findSet(p[x]);
            }
            return p[x];
        }
};

int main(void){
	int n, m, q; cin >> n >> m >> q;
	vector<pair<int, int> > cd;
	set<pair<int, int> > s;//最後まで残っている橋を入れる

	for (int i = 0; i < m; ++i){
		int a, b; cin >> a >> b;
		a--; b--;
		s.insert(make_pair(a, b));
	}
	for (int i = 0; i < q; ++i){
		int c, d; cin >> c >> d;
		c--; d--;
		cd.push_back(make_pair(c, d));
		s.erase(make_pair(c, d));
	}

	DisjointSet ds = DisjointSet(n);
	for(auto u : s){
		ds.unite(u.first, u.second);
	}

    vector<int> ans(n, 0);
    for (int i = 1; i < n; ++i){
    	if(ds.same(0, i)){
    		ans[i] = -1;
    	}
    }

    //O(NQ)
    /*
    for (int i = q - 1; i >= 0 ; --i){
    	ds.unite(cd[i].first, cd[i].second);
    	for (int j = 1; j < n; ++j){
    		if(ans[j] == 0 && ds.same(0, j)){
    			ans[j] = i + 1;
    		}
    	}
    }
    */
    for (int i = q - 1; i >= 0 ; --i){
    	ds.unite(cd[i].first, cd[i].second);
    	for (int j = 1; j < n; ++j){
    		if(ans[j] == 0 && ds.same(0, j)){
    			ans[j] = i + 1;
    		}
    	}
    }
    for (int i = 1; i < n; ++i){
    	printf("%d\n", ans[i]);
    }
	return 0;
}