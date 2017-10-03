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


const int MAX_N = 100010;
//Quick Find Weighted
class QuickFindWeighted{
    public:
        int i2g[MAX_N];//i2g[i] := 頂点iが所属するグループ
        vector<int> g2i[MAX_N];//g2i[g]:= グループgに所属する頂点番号
        void init(int n){
            for (int i = 0; i < n; ++i){
                i2g[i] = i;
                g2i[i].push_back(i);
            }
        }
        // 座標iaと座標ibは同じグループに所属しているか？
        bool issame(int ia, int ib){
            return i2g[ia] == i2g[ib];
        }
        // 座標iaの所属するグループと座標ibの所属するグループを1つにする(異なるグループに属するものに)
        void merge(int ia, int ib){
            if(issame(ia, ib)) return;
            //iaの所属するグループがibの所属するグループより小さくならないようにする(一般的マージテク)
            if(g2i[i2g[ia]].size() < g2i[i2g[ib]].size()){
                swap(ia, ib);
            }else if(g2i[i2g[ia]].size() == g2i[i2g[ib]].size() && i2g[ia] > i2g[ib]) {
                swap(ia, ib);
            }

            int ga = i2g[ia], gb = i2g[ib];//グループgbの方が要素数が少ない
            for(auto u : g2i[gb]){//uには頂点の番号はいる
                i2g[u] = ga;//グループの番号を更新
            }
            g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());//つなげる
            g2i[gb].clear();
        }
};

int main(void) {
    int n, m;
    int a[100010], b[100010];
    cin >> n >> m;
    rep(i, m) cin >> a[i] >> b[i];
    rep(i, m) a[i]--, b[i]--;

    QuickFindWeighted uf;
    uf.init(n);

    rep(i, m) {
        if(!uf.issame(a[i], b[i])) {
            uf.merge(a[i], b[i]);
        }
    }

    rep(i, n) {
        printf("%d\n", uf.i2g[i] + 1);
    }
    return 0;
}
