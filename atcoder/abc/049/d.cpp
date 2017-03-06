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

int n, k, l;
int main(void){
    cin >> n >> k >> l;
    DisjointSet uf1(n), uf2(n);
    rep(i, k){
        int p, q; cin >> p >> q;
        p--; q--;
        uf1.unite(p, q);
    }
    rep(i, l){
        int r, s; cin >> r >> s;
        r--; s--;
        uf2.unite(r, s);
    }
    map<pair<int, int>, int> mapp;
    rep(i, n){
        int d1 = uf1.findSet(i), d2 = uf2.findSet(i);
        if(mapp.find(pair<int, int>(d1, d2)) != mapp.end()){
            mapp[pair<int, int>(d1, d2)]++;
        }else{
            mapp[pair<int, int>(d1, d2)] = 1;
        }
    }
    rep(i, n){
        int d1 = uf1.findSet(i), d2 = uf2.findSet(i);
        auto ret = mapp[pair<int, int>(d1, d2)];
        printf("%d\n", ret);
    }
    return 0;
}
