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

int N, A, B, C, D;
ll dp[1010][1010]; // dp[i][j] := (A + i)の人数のグループまでの見て, それまでの合計人数jの時の場合の数

const int MAX_N = 1010;
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



int main(void) {
	cin >> N >> A >> B >> C >> D;
	MATH ma;
	dp[0][0] = 1;
	rep(i, B - A + 1) { // i人のグループを
		ll size = A + i;
		rep(j, N + 1) { // 合計人数がj人のグループに
			if(dp[i][j] == 0) continue;
			// 0こ
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			// C~D個つかう 
			reps(k, C, D + 1) { // kグループ分追加する
				if(j + size * k > N) break;
				ll t = 1;
				rep(l, k) {
					printf("%lld = %lld C %lld\n", ma.nCk(size * (k - l), size), size * (k - l), size);
					(t *= ma.nCk(size * (k - l), size)) %= MOD;
					// printf("t %lld\n", t);
				}
				printf("t %lld\n", t);
				(t *= facInv[k]) %= MOD;
				// printf("t %lld\n", t);
				// printf("ok %lld\n", inv[k] * facInv[k] % MOD);
				// printf("t %lld\n", t);

				// printf("size %d %d %d %lld\n", size, j, k, t);
				(dp[i + 1][j + size * k] += dp[i][j] * t) %= MOD;
				printf("dp[%d][%d](%lld) = dp[%d][%d](%lld) * %lld\n", i + 1, j + size * k, dp[i + 1][j + size * k], i, j, dp[i][j], t);
			}
		}
	}
	printf("%lld\n", dp[B - A + 1][N]);

	return 0;
}