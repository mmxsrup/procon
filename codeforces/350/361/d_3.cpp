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
class RMQ_max{
public:
	int n;
	vector<T> dat;
	RMQ_max(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, -INF); //(1) 初期値を最小に
	}

	void update(int k, T v) { //1index
        for (dat[k += n] = v; k > 1; k >>= 1) {
            dat[k >> 1] = max(dat[k], dat[k ^ 1]); //(2) 最大値
        }
    }
 
    T query(int l, int r) {
        T res = -INF; //(3) 初期値を最小に
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, dat[l++]); // (3) 最大値
            if (r & 1) res = max(res, dat[--r]); // (4) 最大値
        }
        return res;
    }
};
template <class T> //T : dat[]の中身の型
class RMQ_min{
public:
	int n;
	vector<T> dat;
	RMQ_min(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, INF); //(1) 初期値を最大に
	}

	void update(int k, T v) { // 1index
        for (dat[k += n] = v; k > 1; k >>= 1) {
            dat[k >> 1] = min(dat[k], dat[k ^ 1]); //(2) 最小値
        }
    }
 
    T query(int l, int r) {
        T res = INF; //(3) 初期値を最大に
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = min(res, dat[l++]); // (3) 最小値
            if (r & 1) res = min(res, dat[--r]); // (4) 最小値
        }
        return res;
    }
};


int main(void){
	int n;
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	rep(i, n)scanf("%d", &b[i]);
	RMQ_max<int> sega(n);
	RMQ_min<int> segb(n);

	reps(i, 1, n + 1) sega.update(i, a[i]);
	reps(i, 1, n + 1) segb.update(i, b[i]);

	ll ret = 0;
	rep(i, n){ // 左端
		printf("left %d\n", i);
		int l = i, r = n;
		int ansl, ansr;
		while(r - l > 1){
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			printf("m : %d %lld %lld\n", m, da, db);
			if(da < db) l = m;
			else r = m;
			printf("%d %d\n", l, r);
		}
		printf("query1 %lld %lld %d %d\n", sega.query(i, l + 1), segb.query(i, l + 1), l, r);
		if(sega.query(i, l + 1) == segb.query(i, l + 1))ansl = l;
		else continue;

		l = ansl, r = n;
		while(r - l > 1){
			int m = (l + r) / 2;
			auto da = sega.query(i, m); //単調増加
			auto db = segb.query(i, m); //単調減少
			printf("m : %d %lld %lld\n", m, da, db);
			if(da <= db) l = m;
			else r = m;
		}
		printf("query2 %lld %lld %d %d\n", sega.query(i, l), segb.query(i, l), l, r);

		ansr = l;
		//[ansl, ansr]までが左端の範囲
		printf("ans %d %d\n", ansl, ansr);
		ret += ansr - ansl;
	}
	printf("%lld\n", ret);
	return 0;
}