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
		k += n - 1; //葉の節点
		dat[k] = val;
		while(k > 0){
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]); // (2) 区間の最小値で更新
		}
	}
	T query(int a, int b, int k, int l, int r){ //[a, b)の最大値を求める
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