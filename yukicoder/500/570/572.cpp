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

ll n, m;
ll A[40][40];
ll dp[40][40][40]; // dp[i][j][k] := 長さが2^iで, j->k の音符列の時の最大値
ll ans[40][40][40];

int main(void) {
	cin >> n >> m;
	rep(i, m)rep(j, m) cin >> A[i][j];
	rep(i, m)rep(j, m) dp[0][i][j] = A[i][j];
	rep(i, 35) {
		rep(j, m)rep(k, m) {
			// j-> t , t->v の最大値を計算
			rep(t, m) chmax(dp[i + 1][j][k], dp[i][j][t] + dp[i][t][k]);
		}
	}

	int idx = 0;
	n--;
	rep(i, 35) if(n & (1ll<<i)) {
		rep(j, m)rep(k, m)rep(l, m) { // j -> k -> l (k->lの長さが2^i)
			chmax(ans[idx + 1][j][l], ans[idx][j][k] + dp[i][k][l]);
		}
		idx++;
	}
	ll ret = 0;
	rep(i, m)rep(j, m) chmax(ret, ans[idx][i][j]);
	printf("%lld\n", ret);
	return 0;
}