#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//区間に⼀様に数を⾜すと区間の中での最⼩値を取得をできるsegtree
const int MAX_N = 1 << 20;
const ll INF = 1e9;
int size;
ll seg[MAX_N * 2], lazy[MAX_N * 2];//segは欲しい情報 lazyは区間に対する一様な処理を示すもの?
struct segtree{
    //seg:区間の最小値 lazy:区間に対して、加える値でまだ遅延しているもの
    segtree(int n){
        size = 1;
        while(size < n) size *= 2;//要素数を2のべき乗に
        for (int i = 0; i < 2 * size - 1; ++i) lazy[i] = 0;//0は遅延しているものがないことを示す
    }

    //遅延評価
    void lazy_evaluate_node(int k, int l, int r){
        if(lazy[k] != 0){//遅延がある時
            //(1)この位置を変える(遅延情報の適用方法)
            seg[k] += lazy[k];//区間[l,r)にすべて同じ値を追加することになっていて、segには最小値が入っているので、加える値を足すだけ
            if(r  - l > 1){
                //(2)この位置を変える(遅延情報の伝搬方法) 今回は数字を加える
                lazy[k * 2 + 1] += lazy[k];//左の子に伝搬
                lazy[k * 2 + 2] += lazy[k];//右の子に伝搬
            }
            lazy[k] = 0;//ノードkは伝搬完了
        }
    }

    //update(a,b,v) := [a,b)を全てvを加える
    void update(int a, int b, ll v, int k = 0, int l = 0, int r = size){
        lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
        if(r <= a || b <= l) return;//[a,b)がノードkの区間[l, r)と交差しない
        if(a <= l && r <= b){//[a,bが[l,r)を完全に含んでいる
            //(5)この位置を変える(遅延情報のの更新)
            lazy[k] += v;//ノードkの区間[l,r)を全てvを加えるa
            lazy_evaluate_node(k, l, r);//一回遅延評価しとかないと都合悪い?? ([l,r)の葉の数字は全て同じ値)
        }else{
            update(a, b, v, k * 2 + 1, l, (l + r) / 2);
            update(a, b, v, k * 2 + 2, (l + r) / 2, r);
            //(3)この位置を変える (値のマージ)
            seg[k] = min(seg[k * 2 + 1], seg[k * 2 + 2]);//ノードkを更新 ２つの子の最小値
        }
    }

    //get(a,b) := [a,b)に対する最小値を求める
    ll get(int a, int b, int k = 0, int l = 0, int r = size){
        lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
        if(r <= a || b <= l) return INF;//[a,b)がノードkの区間[l, r)と交差しない時INFを返す
        if(a <= l && r <= b) return seg[k];//[a,bが[l,r)を完全に含んでいる時そのノードの値を返す
        ll x = get(a, b, k * 2 + 1, l, (l + r) / 2);//左の子の最小値
        ll y = get(a, b, k * 2 + 2, (l + r) / 2, r);//右の子の最小値
        //(4)この位置を変える(欲しい値の戻り値) (3)と同じ感じに
        return min(x, y);
    }
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
            ans[u] = a[k[u] - 1] + st.get(s[u] - 1, t[u] + 1);//初項と範囲の最小値
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