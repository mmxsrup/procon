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

template <class Monoid> //segtreeにのせるMonoid
class segtree{
private:
	using T = typename Monoid::T;
	Monoid op;
	int n;
public:
	vector<T> dat;
	segtree(int n_): n(1){ //n_:要素数
		while(n < n_) n <<= 1;
		dat.resize(n * 2, op.neutral()); //初期値
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		dat[k += n] = val;
		while(k > 1){
			k >>= 1;
			dat[k] = op(dat[k * 2], dat[k * 2 + 1]); //可換に注意
		}
	}
	T query(int l, int r){ //[l, r)の区間
		T retl = op.neutral(), retr = op.neutral();
		for (l += n, r += n; l < r; l >>= 1, r >>= 1){
			// 可換に注意
			if(l & 1) retl = op(retl, dat[l++]);
			if(r & 1) retr = op(dat[r - 1], retr);
		}
		return op(retl, retr);
	}
};

struct RMQ{
	using T = int; //台集合
	T operator () (const T &a, const T &b){ //二項演算
		return min(a, b);
	}
	static const T neutral(){ return (T)1e9;}; //単位元
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
	segtree<RMQ> seg(n);
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