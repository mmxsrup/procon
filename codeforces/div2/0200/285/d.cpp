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
		return l + r;
	}
	segtree(int n_, T val): n(n_), neutral(val) { //n_:要素数 val:単位元
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, neutral); //初期値
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		k += n - 1;
		dat[k] += val;
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

int n;
int a[200010], b[200010];
int p[200010], q[200010], pq[200010];

int main(void){
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) scanf("%d", &b[i]);
	segtree<int> segp(n , 0), segq(n, 0), segpq(n , 0);
	rep(i, n) {
		p[i] = segp.query(0, a[n - i - 1]);
		segp.update(a[n - i - 1], 1);
	}
	rep(i, n){
		q[i] = segq.query(0, b[n - i - 1]);
		segq.update(b[n - i - 1], 1);
	}
	// rep(i, n) printf("%d ", p[i]);
	// printf("\n");
	// rep(i, n) printf("%d ", q[i]);
	// printf("\n");
	// 繰り上げ
	int k = 0;
	reps(i, 1, n){
		pq[i] = (p[i] + q[i] + k) % (i + 1);
		k = (p[i] + q[i]) / (i + 1);
	}
	// rep(i, n) printf("%d ", pq[i]);
	// printf("\n");	

	segtree<int> t(n, 0);
	vector<int> ans(n);
	for (int i = n - 1; i >= 0 ; --i){
		
		int l = 0, r = n;
		while(r - l > 1){
			int m = (l + r) / 2;
			int ret = t.query(i, m + 1);
			int d = m - ret;
			printf("l %d r %d ret %d d %d\n", l, r, ret, d);

			if(d < pq[i]) r = m;
			else l = m;
		}
		printf("l %d\n", l);
		ans[i] = l;
		
		/*
		rep(j, n){
			int ret = j - t.query(0, j + 1);
			// printf("i %d j %d ret %d\n", i, j, ret);
			if(ret == pq[i]){
				// printf("k\n");
				ans[i] = j;
				break;
			}
		}
		*/
		t.update(ans[i], 1);
	}
	for (int i = n - 1; i >= 1; --i){
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[0]);
	return 0;
}