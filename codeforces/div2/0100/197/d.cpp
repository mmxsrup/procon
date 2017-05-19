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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
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
		dat.resize(n * 2, 0); //(1) 単位元
	}
	void update(int k, T val){ // k番目の値(0-indexed)を val に変更
		k += n - 1; //葉の節点
		dat[k] = val;
		int cnt = 0;
		while(k > 0){
			k = (k - 1) / 2;
			if(cnt % 2)dat[k] = dat[k * 2 + 1] ^ dat[k * 2 + 2];
			else dat[k] = dat[k * 2 + 1] | dat[k * 2 + 2];
			cnt++;
		}
	}
};

int n, m;

int main(void){
	cin >> n >> m;
	segtree<int> seg(pow(2, n)); //大きさに注意
	rep(i, pow(2, n)){
		int a; cin >> a;
		seg.update(i, a);
	}
	
	rep(i, m){
		int p, b; cin >> p >> b;
		p--;
		seg.update(p, b);
		printf("%d\n", seg.dat[0]);
	}

	return 0;
}