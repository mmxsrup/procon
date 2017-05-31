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


template <class T> //T(モノイド) : dat[]の中身の型
class segtree{
public:
	int n;
	T neutral;
	vector<T> dat;
	T func(T l, T r) { //二項演算子
		int lok, lopen, lclose, rok, ropen, rclose;
		tie(lok, lopen, lclose) = l;
		tie(rok, ropen, rclose) = r;
		int add = min(lopen, rclose);
		return make_tuple(lok + rok + 2 * add, lopen + ropen - add, lclose + rclose - add);
	}
	segtree(int n_, T val): n(n_), neutral(val) { //n_:要素数 val:単位元
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, neutral); //初期値
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		k += n - 1;
		dat[k] = val;
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = func(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}
	T query(int a, int b, int k, int l, int r) { //[a, b)の区間
		if(r <= a || b <= l) return neutral;
		if(a <= l && r <= b) return dat[k];
		else {
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return func(vl, vr);
		}
	}
	T query(int a, int b) {
		return query(a, b, 0, 0, n);
	}
};


int m, l[100010], r[100010];
int main(void) {
	string s; cin >> s;
	segtree<tuple<int, int, int>> seg(s.size(), make_tuple(0, 0, 0));
	rep(i, s.size()) {
		if(s[i] == '(') seg.update(i, make_tuple(0, 1, 0));
		else seg.update(i, make_tuple(0, 0, 1));
	}

	scanf("%d", &m);
	rep(i, m) scanf("%d %d", &l[i], &r[i]);
	rep(i, m){
		auto ret = seg.query(l[i] - 1, r[i]);
		int a, b, c; tie(a, b, c) = ret;
		printf("%d\n", a);
	}
	return 0;
}