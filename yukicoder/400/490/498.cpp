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

int Gx, Gy, K;
int x[6], y[6], N[6];
map<pair<int, int>, int> mpp;
vector<tuple<int, int, int>> v;
vector<int> fin;
set<vector<int>> ans;

void slv(vector<int> g, int nx, int ny){
	if(nx == Gx && ny == Gy) ans.insert(g);
	if(g == fin) return;
	// printf("%d %d\n", g[0], g[1]);
	rep(i, K){
		int tx, ty, tN; tie(tx, ty, tN) = v[i];
		if(g[i] < tN){
			auto tmp = g;
			tmp[i]++;
			slv(tmp, nx + tx, ny + ty);
		}
	}
}


const int MAX_N = 20;
ll inv[MAX_N + 10];
ll fac[MAX_N + 10], facInv[MAX_N + 10];
class MATH{
public:
	MATH(){
		inverse();
		factroial();
	}
	ll nCk(ll n, ll k){// n! / k!*(n-k)!
		if(k < 0 || k > n) return 0;
		ll ret = fac[n];
		(ret *= facInv[k]) %= MOD;
		(ret *= facInv[n - k]) %= MOD;
		return ret;
	}
	ll nHk(ll n, ll k){// nHk = n+k-1 C k = (n+k-1)! / k! * (n-1)!
		if(n == 0 && k == 0) return 1;
		ll ret = fac[n + k - 1];
		(ret *= facInv[k]) %= MOD;
		(ret *= facInv[n - 1]) %= MOD;
		return ret;
	}
	ll nPk(ll n, ll k){//nPk = n! / (n-k)!
		if(k < 0 || k > n) return 0;
		ll ret = fac[n];
		(ret *= facInv[n - k]) %= MOD;
		return ret;
	}
private:
	void inverse(void){
		inv[1] = 1;
		for (int i = 2; i <= MAX_N; ++i){
			// inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
			inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
		}
	}
	void factroial(void){
		fac[0] = facInv[0] = 1;
		for (int i = 1; i <= MAX_N; ++i){
			fac[i] = (fac[i - 1] * i) % MOD;
			facInv[i] = (facInv[i - 1] * inv[i]) % MOD;
		}
	}
};


int main(void){
	cin >> Gx >> Gy >> K;
	rep(i, K) cin >> x[i] >> y[i] >> N[i];
	rep(i, K) mpp[mp(x[i], y[i])] += N[i];
	for(auto u : mpp){
		v.pb(make_tuple(u.fi.fi, u.fi.se, u.se));
	}
	vector<int> t;
	rep(i, K) t.pb(0);
	rep(i, K) fin.pb(N[i]);
	slv(t, 0, 0);
	ll ret = 0;
	MATH mt;
	for(auto r : ans){
		int d = 0;
		ll anstmp = 0;
		rep(i, r.size()){
			d += r[i];
			// printf("%d ", r[i]);
		}
		// printf("\n");
		anstmp = fac[d];
		anstmp %= MOD;
		rep(i, r.size()){
			anstmp *= facInv[r[i]];
			anstmp %= MOD;
		}
		ret += anstmp;
		ret %= MOD;
	}
	cout << ret << endl;
	return 0;
}