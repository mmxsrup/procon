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
int a[200010], b[200010];

template <class T> //T : dat[]の中身の型
class segtree_max{
public:
	int n;
	vector<T> dat;
	segtree_max(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, -INF); //(1) 初期値を最小に -INFかも
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		for (dat[k += n] = val; k > 0; k >>= 1){ // kを含む区間のインデックスを下から順に列挙
			dat[k>>1] = max(dat[k], dat[k ^ 1]); // (2) 区間の最大値で更新
		}
	}
	T query(int l, int r){
		T ret = -INF; //(3) 最大値に関係ない値 -INFかも
		for (l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) ret = max(ret, dat[l++]); //(4) 区間の最大値で更新
			if(r & 1) ret = max(ret, dat[--r]); //(4) 区間の最大値で更新
		}
		return ret;
	}
};

template <class T> //T : dat[]の中身の型
class segtree_min{
public:
	int n;
	vector<T> dat;
	segtree_min(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, INF); //(1) 初期値を最大に
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		for (dat[k += n] = val; k > 0; k >>= 1){ // kを含む区間のインデックスを下から順に列挙
			dat[k>>1] = min(dat[k], dat[k ^ 1]); // (2) 区間の最大値で更新
		}
	}
	T query(int l, int r){
		T ret = INF; //(3) 最小値に関係ない値
		for (l += n, r += n; l < r; l >>= 1, r >>= 1){
			if(l & 1) ret = min(ret, dat[l++]); //(4) 区間の最小値で更新
			if(r & 1) ret = min(ret, dat[--r]); //(4) 区間の最小値で更新
		}
		return ret;
	}
};

int main(void){
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	rep(i, n)scanf("%d", &b[i]);
	segtree_max<int> sega(n + 1);
	segtree_min<int> segb(n + 1);

	rep(i, n) sega.update(i, a[i]);
	sega.update(n, INF + 1); //右端を追加
	rep(i, n) segb.update(i, b[i]);
	segb.update(n, -1); //右端を追加

	ll ret = 0;
	rep(i, n){ // 左端
		int l = i, r = n + 1;
		int ansl, ansr;
		while(r - l > 1){ // lower_bound
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			if(da < db) l = m;
			else r = m;
		}
		if(sega.query(i, l + 1) == segb.query(i, l + 1))ansl = l;
		else continue;

		l = ansl, r = n + 1;
		while(r - l > 1){ //upper_bound
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			if(da < db + 1) l = m;
			else r = m;
		}
		ansr = l;
		//[ansl, anrl], .. , [ansl, ansr - 1] までが答えの区間
		ret += ansr - ansl;
	}
	printf("%lld\n", ret);
	return 0;
}