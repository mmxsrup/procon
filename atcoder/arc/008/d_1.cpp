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

struct RMQ {
	using T = int;
	T operator()(const T& a, const T& b) { return a < b ? a : b; }
	static constexpr T identity() { return INT_MAX; }
};

template <class T> //T : dat[]の中身の型
class segtree{
public:
	int n;
	T neutral;
	vector<T> dat;
	T func(T l, T r){ //区間をマージする関数
		return make_pair(l.fi * r.fi, l.se * r.fi + r.se);
	}
	segtree(int n_, T val): n(n_), neutral(val){ //n_:要素数 val:単位元
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, neutral); //初期値
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		dat[k += n] = val;
		while(k > 1){
			k >>= 1;
			dat[k] = func(dat[k * 2], dat[k * 2 + 1]); //結合法則を考える
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

ll N; int M;
ll p[100010];
double a[100010], b[100010];
int main(void){
	cin >> N >> M;
	rep(i, M) cin >> p[i] >> a[i] >> b[i];
	vector<ll> v(M);
	rep(i, M) v[i] = p[i];
	sort(all(v));
	v.erase(unique(v.begin(), v.end()), v.end());
	segtree<pair<double, double>> seg(M, make_pair(1.0, 0.0));
	double mi = 1, ma = 1;
	rep(i, M){
		int idx = lower_bound(all(v), p[i]) - v.begin();
		seg.update(idx, make_pair(a[i], b[i]));
		auto f = seg.query(0, M);
		double ret = 1.0 * f.fi + f.se;
		chmin(mi, ret); chmax(ma, ret);
	}
	printf("%.9f\n", mi);
	printf("%.9f\n", ma);
	return 0;
}