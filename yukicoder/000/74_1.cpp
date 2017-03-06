#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
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
    int n; cin >> n;
    DisjointSet ds = DisjointSet(n);
    vector<int> d(n);
    vector<int> w(n);
    rep(i, n) cin >> d[i];
    rep(i, n) cin >> w[i];

    vector<bool> flag(n, false);//1つだけで反転できるやつはtrue
    for (int i = 0; i < n; ++i){
        int l = (i - d[i] + 1000 * n) % n;
        int r = (i + d[i]) % n;
        ds.unite(l, r);
        if(l == r) flag[l] = true;
    }

    vector<int> ura(n, 0); //根がiのもので初めに裏が奇数のものの数
    vector<bool> iti(n, false); //根がiで一枚で反転できやつが存在するか
    for (int i = 0; i < n; ++i){
        int ret = ds.findSet(i);
        if(w[ret] == 0) ura[ret]++;
        if(flag[ret]) iti[ret] = true;
    }
    rep(i, n){
        if(ura[i] % 2 != 0 && !iti[i]){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}