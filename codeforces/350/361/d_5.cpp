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

template <class T> //T : table[][]の中身の型
class SparseTable_max{
public:
	int N, M; //table[N][M]
	// table[i][k] := [i, i + 2^k)の最大値
	vector<vector<T>> table;
	template<class S> SparseTable_max(int n, S &val): N(n){ // O(nlogn)
		M = 32 - __builtin_clz(N); // M - 1 <= logN < M
		table.resize(N, vector<T>(M));
		for (int i = 0; i < N; ++i){ // [i, i + 1)までの区間の最大値
			table[i][0] = val[i];
		}
		for (int k = 0; k < M - 1; ++k){ // [i, i + 2^(k+1))の区間を計算
			for (int i = 0; i + (1<< k) < N; ++i){
				// iから2^(k+1)の長さの区間の最小値を2^kの長さの区間の最大値を利用して求める
				table[i][k + 1] = max(table[i][k], table[i + (1 << k)][k]); // (1)最大値
			}
		}
	}
	T query(int l, int r){ // O(1) [l, r) の間の最大値
		int k = 31 - __builtin_clz(r - l); //区間の長さの半分以上の値 （k<= r - l < k + 1)
		return max(table[l][k], table[r - (1 << k)][k]); // (2) 最大値
	}
};

template <class T> //T : table[][]の中身の型
class SparseTable_min{
public:
	int N, M; //table[N][M]
	// table[i][k] := [i, i + 2^k)の最小値
	vector<vector<T>> table;
	template<class S> SparseTable_min(int n, S &val): N(n){ // O(nlogn)
		M = 32 - __builtin_clz(N); // M - 1 <= logN < M
		table.resize(N, vector<T>(M));
		for (int i = 0; i < N; ++i){ // [i, i + 1)までの区間の最小値
			table[i][0] = val[i];
		}
		for (int k = 0; k < M - 1; ++k){ // [i, i + 2^(k+1))の区間を計算
			for (int i = 0; i + (1<< k) < N; ++i){
				// iから2^(k+1)の長さの区間の最小値を2^kの長さの区間の最小値を利用して求める
				table[i][k + 1] = min(table[i][k], table[i + (1 << k)][k]); // (1)最小値
			}
		}
	}
	T query(int l, int r){ // O(1) [l, r) の間の最小値
		int k = 31 - __builtin_clz(r - l); //区間の長さの半分以上の値 （k<= r - l < k + 1)
		return min(table[l][k], table[r - (1 << k)][k]); // (2) 最小値
	}
};

int main(void){
	scanf("%d", &n);
	rep(i, n)scanf("%d", &a[i]);
	a[n] = INF + 1;
	rep(i, n)scanf("%d", &b[i]);
	b[n] = -1;
	SparseTable_max<int> sega(n + 1, a);
	SparseTable_min<int> segb(n + 1, b);

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