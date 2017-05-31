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

template <class T> //T : dat[]の中身の型
class segtree{
public:
	int n;
	vector<T> dat;
	segtree(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, 0);
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		k += n - 1; //葉の節点
		dat[k] = val;
		while(k > 0){
			k = (k - 1) / 2;
			dat[k] = dat[k * 2 + 1] + dat[k * 2 + 2];
		}
	}
	T query(int a, int b, int k, int l, int r){ //[a, b)の最大値を求める
		if(r <= a || b <= l) return 0;
		if(a <= l && r <= b) return dat[k];
		else{
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return vl + vr; //(4) 区間の最大値で更新
		}
	}
	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

int n;
int a[1000100];
// sum[l] := [0, l]の中でa[l]の数 / sum[r] := [r, n - 1]の中でa[r]の数
int suml[1000100], sumr[1000100];
map<int, int> mal, mar;

int main(void){
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) suml[i] = mal[a[i]] + 1, mal[a[i]]++;
	REP(i, n) sumr[i] = mar[a[i]] + 1, mar[a[i]]++;
	/*

	printf("mal\n");
	rep(i, n) printf("%d ", suml[i]);
	printf("\n");
	rep(i, n) printf("%d ", sumr[i]);
	printf("\n");
	*/
	segtree<int> seg(n + 10);
	ll ans = 0;
	rep(j, n){ // j を動かす
		/*
		printf("sumr %d\n", sumr[j]);
		int d = seg.query(0, sumr[j] + 1); // i < j で f(l,i,ai)<=f(j,n,aj)となる iの数
		printf("d %d\n", d);
		ans += j - d; // i < j で f(l,i,ai)>f(j,n,aj)となる i の 数
		printf("j - d %d\n", j - d);
		seg.update(suml[j], 1);
		*/
		printf("query %d \n", seg.query(sumr[j] + 1, n + 1));


		ans += seg.query(sumr[j] + 1, n + 1); // i < j で f(l, i, ai) > f(j, n, aj) となる iの数

		seg.update(suml[j], 1);
	}
	printf("%lld\n", ans);
	return 0;
}