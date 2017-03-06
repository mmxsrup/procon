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

class Euler_Tour{
public:
	vector<vector<int> > g;
	//begin[v],end[v]はそれぞれvがオイラーツアー上で最初と最後に現れるインデックス
	//[begin[v], end[v])がvを根とする部分木
	vector<int> euler_tour, begin, end;
	Euler_Tour(int n) : g(n), begin(2 * n), end(2 * n){};//nは頂点数
	int k = 0, root = 0;
	void dfs(int curr, int par){//現在　parent
		begin[curr] = k;
		euler_tour.push_back(curr);
		k++;
		for(auto next : g[curr]){
			if(next == par) continue;
			dfs(next, curr);
			euler_tour.push_back(curr);
			k++;
		}
		end[curr] = k;
	}
};

//(1)区間に一様加算 (2)区間の最小値
struct segtree{
public:
    const int SIZE = 1 << 20;
	//seg:区間の最小値 lazy:区間に対して、加える値でまだ遅延しているもの
	vector<int> seg, lazy;//segは欲しい情報 lazyは区間に対する一様な処理を示すもの
    segtree():seg(SIZE * 2), lazy(SIZE * 2){}
    void lazy_evaluate(int k, int l, int r){//遅延情報の適用方法
        if(lazy[k] != 0){
            seg[k] += lazy[k];//区間[l,r)にすべて同じ値を追加することになっていて、segには最小値が入っているので、加える値を足す
            if(r  - l > 1){
                lazy[k * 2 + 1] += lazy[k];//遅延を左の子に伝搬
                lazy[k * 2 + 2] += lazy[k];//遅延を右の子に伝搬
            }
            lazy[k] = 0;//ノードkは伝搬完了
        }
    }
    void update(int a, int b, int k, int l, int r, int x){
        lazy_evaluate(k, l, r);
        if(r <= a || b <= l) return;
        if(a <= l && r <= b){
            lazy[k] += x; //加える
            lazy_evaluate(k, l, r);
        }else{
            update(a, b, k * 2 + 1, l, (l + r) / 2, x);
            update(a, b, k * 2 + 2, (l + r) / 2, r, x);
            seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]); //区間のmin
        }
    }  
    int query(int a, int b, int k, int l, int r){
        lazy_evaluate(k, l, r);
        if(r <= a || b <= l) return INF;//minの影響のないもの
        if(a <= l && r <= b) return seg[k];
        int x = query(a, b, k * 2 + 1, l, (l + r) / 2);
        int y = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(x, y); //左右のminを
    }
    //update(a,b,x) := [a,b)を全てxを加える
    void update(int a, int b, int x){update(a, b, 0, 0, SIZE, x);}
    //query(a,b) := [a,b)に対する最小値を求める
    int query(int a, int b){return query(a, b, 0, 0, SIZE);}
};

int n, m;
int a[200010];
segtree even, odd;

int main(void){
	scanf("%d %d", &n, &m);
	rep(i, n) scanf("%d", &a[i]);
	Euler_Tour et(n);

	rep(i, n - 1){
		int u, v; scanf("%d %d", &u, &v); u--; v--;
		et.g[u].pb(v);
		et.g[v].pb(u);
	}
	et.dfs(0, -1);
	rep(i, n){
		if(et.begin[i] % 2 == 0) even.update(et.begin[i], et.begin[i] + 1, a[i]);
		else odd.update(et.begin[i], et.begin[i] + 1, a[i]);
	}
	rep(i, m){
		int q; cin >> q;
		if(q == 1){
			int x, val; scanf("%d %d", &x, &val); x--;
			if(et.begin[x] % 2 == 0){
				even.update(et.begin[x], et.end[x], val);
				odd.update(et.begin[x], et.end[x], -val);
			}else{
				even.update(et.begin[x], et.end[x], -val);
				odd.update(et.begin[x], et.end[x], val);
			}
		}else{
			int x; scanf("%d", &x); x--;
			if(et.begin[x] % 2 == 0) printf("%d\n", even.query(et.begin[x], et.begin[x] + 1));
			else printf("%d\n", odd.query(et.begin[x], et.begin[x] + 1));
		}
	}
	return 0;
}