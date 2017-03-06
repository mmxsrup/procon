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

const int MAX_N = 1 << 18;
ll seg[MAX_N * 2], lazy[MAX_N * 2];//segは欲しい情報 lazyは区間に対する一様な処理を示すもの
struct segtree{
public:
    int SIZE;
    //seg:区間の最小値 lazy:区間に対して、加える値でまだ遅延しているもの
    segtree(int n){
        SIZE = 1;
        while(SIZE < n) SIZE *= 2;//要素数を2のべき乗に
        for (int i = 0; i < 2 * SIZE - 1; ++i) lazy[i] = 0;//0は遅延しているものがないことを示す
    }
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
    void update(int a, int b, int k, int l, int r, ll x){
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
    ll query(int a, int b, int k, int l, int r){
        lazy_evaluate(k, l, r);
        if(r <= a || b <= l) return INF;//minの影響のないもの
        if(a <= l && r <= b) return seg[k];
        ll x = query(a, b, k * 2 + 1, l, (l + r) / 2);
        ll y = query(a, b, k * 2 + 2, (l + r) / 2, r);
        return min(x, y); //左右のminを
    }
    //update(a,b,x) := [a,b)を全てxを加える
    void update(int a, int b, int x){update(a, b, 0, 0, SIZE, x);}
    //query(a,b) := [a,b)に対する最小値を求める
    ll query(int a, int b){return query(a, b, 0, 0, SIZE);}
};

int l[100010], r[100010], x[100010];
int s[100010], t[100010], k[100010];
vector<pair<int, int> > add[100010], del[100010];
vector<int> query[100010];
int main(void){
    int n; cin >> n;
    vector<int> a(n); rep(i, n) cin >> a[i];
    int A; cin >> A;
    //a[i]のi列に対しての処理ごとにリスト化
    rep(i, A){
        cin >> l[i] >> r[i] >> x[i];
        add[l[i]].push_back(make_pair(i, x[i]));
        del[r[i]].push_back(make_pair(i, x[i]));
    }
    int B; cin >> B;
    //a[i]のi列に対しての処理ごとにリスト化
    rep(i, B){
        cin >> s[i] >> t[i] >> k[i];
        query[k[i]].push_back(i);//ai列目に対するクエリが何個目のクエリなのか
    }

    ll ans[100010];//ans[i] := i番目のクエリに関する答え
    segtree st(A + 1);
    //a1列からan列へ順番に見ていく(それぞれの列の初期値は無視して、増加現象部分のみの列としてみる)
    for (int i = 1; i <= n; ++i){
        st.update(0, 1, 0);
        for(auto u : add[i]){
            st.update(u.first + 1, A + 1, u.second);//[u,A)まで加算
        }
        for(auto u : query[i]){
            ans[u] = a[k[u] - 1] + st.query(s[u] - 1, t[u] + 1);//初項と範囲の最小値
        }
        for(auto u : del[i]){
            st.update(u.first + 1, A + 1, -u.second);//[u,A)まで減算
        }
    }
    rep(i, B){
        printf("%lld\n", ans[i]);
    }
    return 0;
}