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
const ll INFF = 1e18;

ll n, d, k;
ll x[100010];

template <class T> //T : dat[]の中身の型
class segtree{
public:
	int n;
	T neutral;
	vector<T> dat;
	T func(T l, T r){ //区間をマージする関数
		return max(l, r); /* ここを変える */
	}
	segtree(int n_, T val): n(n_), neutral(val){ //n_:要素数 val:単位元
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, neutral); //初期値
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		for (dat[k += n] = val; k > 0; k >>= 1){ // kを含む区間のインデックスを下から順に列挙
			dat[k>>1] = func(dat[k], dat[k ^ 1]);
		}
	}
	T query(int l, int r){ //[l, r)の区間
		T ret = neutral;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) ret = func(ret, dat[l++]);
			if(r & 1) ret = func(ret, dat[--r]);
		}
		return ret;
	}
};

int main(void){
	cin >> n >> d >> k;
	rep(i, n) cin >> x[i];
	segtree<pair<ll, int>> seg(n, make_pair(0, 0));
	rep(i, n) seg.update(i, {x[i], -i}); //辞書順最小のためマイナス
	ll ans = 0; pint idx;
	rep(i, n){
		auto ret = seg.query(i, min(n, i + d + 1));
		if(ret.fi - x[i] > ans){
			ans = ret.fi - x[i]; idx = make_pair(i, -ret.se);
		}
	}
	printf("%lld\n", ans * k); if(ans == 0) return 0;
	printf("%d %d\n", idx.fi, idx.se);
	return 0;
}