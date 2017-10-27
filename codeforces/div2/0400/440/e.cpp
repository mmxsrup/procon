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

int n;
ll x[100010], y[100010];

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
            }
            int ga = i2g[ia], gb = i2g[ib];//グループgbの方が要素数が少ない
            for(auto u : g2i[gb]){//uには頂点の番号はいる
                i2g[u] = ga;//グループの番号を更新
            }
            g2i[ga].insert(g2i[ga].end(), g2i[gb].begin(), g2i[gb].end());//つなげる
            g2i[gb].clear();
        }
};

//x^k mod
long long powmod(long long x, long long k, long long m){ // 繰り返し二乗法(logk)
	if(k == 0) return 1;
	if(k % 2 == 0) return powmod(x * x % m, k / 2, m);
	else return x * powmod(x, k - 1, m) % m;
}

int main(void) {
	scanf("%d", &n);
	rep(i, n) scanf("%lld %lld", &x[i], &y[i]);
	map<int, set<int>> mx, my;
	rep(i, n) mx[x[i]].insert(i);
	rep(i, n) my[y[i]].insert(i);


	QuickFindWeighted uf; uf.init(n);
	rep(i, n) {
		for(auto u : mx[x[i]]) uf.merge(i, u);
		for(auto u : my[y[i]]) uf.merge(i, u);
	}

	ll ans = 1;
	rep(i, n) {
		ll size = uf.g2i[i].size();
		if(size <= 0) continue;
		else if(size == 1) ans *= 3;
		else ans *= powmod(2ll, size, MOD);
		ans %= MOD;
	}
	printf("%lld\n", ans);
	return 0;
}