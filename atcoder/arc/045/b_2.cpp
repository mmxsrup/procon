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

int n, m;
int s[300010], t[300010];
int imos[300010];

template <class T> //T : table[][]の中身の型
class SparseTable{
public:
	int N, M; //table[N][M]
	// table[i][k] := [i, i + 2^k)の最小値
	vector<vector<T>> table;
	template<class S> SparseTable(int n, S &val): N(n){ // O(nlogn)
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
	cin >> n >> m;
	rep(i, m){
		cin >> s[i] >> t[i];
		s[i]--; t[i]--;
	}

	rep(i, m){
		imos[s[i]]++;
		imos[t[i] + 1]--;
	}
	rep(i, n){
		imos[i + 1] += imos[i];
	}
	SparseTable<int> seg(n, imos);
	vector<int> ans;
	rep(i, m){
		if(seg.query(s[i], t[i] + 1) >= 2) ans.pb(i + 1);
	}
	printf("%d\n", (int)ans.size());
	rep(i, ans.size()){
		printf("%d\n", ans[i]);
	}
	return 0;
}