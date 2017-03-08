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

int a[200010], b[200010];

template <class T> //T : dat[]の中身の型
class segtree_max{
public:
	int n;
	vector<T> dat;
	segtree_max(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, -INF); //(1) 初期値を最小に
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		k += n - 1; //葉の節点
		dat[k] = val;
		while(k > 0){
			k = (k - 1) / 2;
			dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]); // (2) 区間の最大値で更新
		}
	}
	T query(int a, int b, int k, int l, int r){ //[a, b)の最大値を求める
		if(r <= a || b <= l) return -INF; //(3) 最大値に関係ない値で更新
		if(a <= l && r <= b) return dat[k];
		else{
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return max(vl, vr); //(4) 区間の最大値で更新
		}
	}
	T query(int a, int b){
		return query(a, b, 0, 0, n);
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
		k += n - 1; //葉の節点
		dat[k] = val;
		while(k > 0){
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // (2) 区間の最小値で更新
		}
	}
	T query(int a, int b, int k, int l, int r){ //[a, b)の最小値を求める
		if(r <= a || b <= l) return INF; //(3) 最小値に関係ない値で更新
		if(a <= l && r <= b) return dat[k];
		else{
			T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr); //(4) 区間の最小値で更新
		}
	}
	T query(int a, int b){
		return query(a, b, 0, 0, n);
	}
};

int main(void){
	int n;
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	rep(i, n)scanf("%d", &b[i]);
	segtree_max<int> sega(n);
	segtree_min<int> segb(n);

	rep(i, n) sega.update(i, a[i]);
	rep(i, n) segb.update(i, b[i]);

	ll ret = 0;
	rep(i, n){ // 左端
		if(a[i] > b[i]) continue;
		// printf("left %d\n", i);
		int l = i, r = n;
		int ansl, ansr;

		l = i, r = n;
		while(r - l > 1){
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			// printf("m : %d %lld %lld\n", m, da, db);
			if(da <= db) l = m;
			else r = m;
		}
		// printf("query1 %lld %lld %d %d\n", sega.query(i, l), segb.query(i, l), l, r);
		if(sega.query(i, l) == segb.query(i, l))ansr = l;
		else continue;

		if(i == ansr){
			ret++; 
			continue;
		}
		
		l = i, r = ansr;
		while(r - l > 1){
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			// printf("m : %d %lld %lld\n", m, da, db);
			if(da < db) l = m;
			else r = m;
		}
		// printf("query2 %lld %lld %d %d\n", sega.query(i, l + 1), segb.query(i, l + 1), l, r);

		ansl = l;
		//[ansl, ansr)までが左端の範囲
		// printf("ans %d %d\n", ansl, ansr);
		ret += ansr - ansl;
	}
	printf("%lld\n", ret);
	return 0;
}