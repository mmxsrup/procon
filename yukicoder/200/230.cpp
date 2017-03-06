#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const int MAX_N = 1 << 18;
//segはその区間での現在の正しい値を持つ このあたはサボれる
//lazyはその区間に評価を遅延している(加えていない、書き換えていない)ものを持つ
//再帰で根から辿りながら、遅延評価を辿った頂点の子に振りまいていきながら、こまめに節点の本当の値を再計算。必要になったときだけ細かく計算すればよいという感じ。
int size;
ll seg[MAX_N * 2], lazy[MAX_N * 2];
struct segtree{
	segtree(int n){
		size = 1;
		while(size < n) size *= 2;//要素数を2のべき乗に
		for (int i = 0; i < 2 * size - 1; ++i) lazy[i] = -INF;
	}

	//遅延評価
	void lazy_evaluate_node(int k, int l, int r){
		if(lazy[k] != -INF){//遅延がある時
			seg[k] = lazy[k] * (r - l);//区間[l,r)がすべてlazy[k](=v)になるから
			if(r  - l > 1){
				lazy[k * 2 + 1] = lazy[k];//左の子に伝搬
				lazy[k * 2 + 2] = lazy[k];//右の子に伝搬
			}
			lazy[k] = -1;//ノードkは伝搬完了
		}
	}

	//update(a,b,v) := [a,b)を全てvに書き換える
	void update(int a, int b, ll v, int k = 0, int l = 0, int r = size){
		lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
		if(r <= a || b <= l) return;//[a,b)がノードkの区間[l, r)と交差しない
		if(a <= l && r <= b){//[a,bが[l,r)を完全に含んでいる
			lazy[k] = v;//ノードkの区間[l,r)を全てvに書き換える
			lazy_evaluate_node(k, l, r);//一回遅延評価しとかないと都合悪い?? ([l,r)の葉の数字は全て同じ値)
		}else{
			update(a, b, v, k * 2 + 1, l, (l + r) / 2);
			update(a, b, v, k * 2 + 2, (l + r) / 2, r);
			seg[k] = seg[k * 2 + 1] + seg[k * 2 + 2];//ノードkを更新 ２つの子の和
		}
	}

	//get(a,b) := [a,b)に対する総和を求める
	ll get(int a, int b, int k = 0, int l = 0, int r = size){
		lazy_evaluate_node(k, l, r);//辿ったノードはついでについでに伝搬しておく
		if(r <= a || b <= l) return 0;//[a,b)がノードkの区間[l, r)と交差しない時0を返す
		if(a <= l && r <= b) return seg[k];//[a,bが[l,r)を完全に含んでいる時そのノードの値を返す
		ll x = get(a, b, k * 2 + 1, l, (l + r) / 2);//左の子の総和
		ll y = get(a, b, k * 2 + 2, (l + r) / 2, r);//右の子の総和
		return x + y;
	}

};

int main(void){
	int n; cin >> n;
	int q; cin >> q;
	segtree st(n);
	// rep(i, n) st.update(i, i + 1, 0);

	rep(i, n){
		printf("%lld ", st.get(i, i + 1));
	}
	printf("\n");

	ll ansa = 0, ansb = 0;
	rep(i, q){
		int x; cin >> x;
		int left, right; cin >> left >> right;
		if(x == 0){//ボーナス
			//x + y = sum, x - y = right - left + 1
			int sum = st.get(left, right + 1);
			printf("sum %d\n", sum);
			if(sum > 0){
				ansa += (sum + right - left + 1) / 2;
			}else if(sum < 0){
				ansb += (right - left + 1 - sum) / 2;
			}
		}else if(x == 1){
			st.update(left, right + 1, 1);
		}else{
			st.update(left, right + 1, -1);
		}
		rep(i, n){
			printf("%d ", (int)st.get(i, i + 1));
		}
		printf("\n");
	}
	rep(i, n){
		if(st.get(i, i + 1) == 1) ansa++;
		else if(st.get(i, i + 1) == -1) ansb++;
	}
	printf("%lld %lld\n", ansa, ansb);
	return 0;
}