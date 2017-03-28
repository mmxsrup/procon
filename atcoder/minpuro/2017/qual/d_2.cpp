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

int q; ll k;
vector<ll> v[100010];

template <class T> //T : dat[]の中身の型
class segtree{
public:
	int n;
	vector<T> dat;
	segtree(int n_): n(n_){ //n_要素数
		n = 1;
		while(n < n_) n *= 2;
		dat.resize(n * 2, 0); //(1) 初期値を最小に
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
		if(r <= a || b <= l) return 0; //(3) 最大値に関係ない値で更新
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

int main(void){
	cin >> q >> k;
	vector<ll> zaatu;
	rep(i, q){
		int t; cin >> t;
		if(t == 1){
			ll d, a; cin >> d >> a;
			v[i].pb(d), v[i].pb(a);
			zaatu.pb(d);
		}else{
			ll d; cin >> d;
			v[i].pb(d);
			zaatu.pb(d);
		}
	}
	/* 座圧 */
	sort(all(zaatu));
	zaatu.erase(eall(zaatu));
	rep(i, q){
		int td = lower_bound(all(zaatu), v[i][0]) - zaatu.begin();
		v[i][0] = td;
	}

}