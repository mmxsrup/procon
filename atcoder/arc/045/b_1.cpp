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

template <class T> //T : dat[]の中身の型
class segtree{
public:
	int n;
	vector<T> dat;
	segtree(int n_): n(n_){ //n_要素数
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
	segtree<int> seg(n);
	rep(i, n){
		seg.update(i, imos[i]);
	}
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