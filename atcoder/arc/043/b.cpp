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

int N;

ll dp[100010][10]; // dp[i][j] := iをj番目に選ぶ場合の数

int main(void){
	cin >> N;
	vector<int> D(N);
	rep(i, N) cin >> D[i];
	sort(all(D));
	int p = 0;
	// rep(i, N) dp[i][0] = 1;
	dp[0][0] = 1;

	rep(i, N){
		/*
		rep(j, 4) {
			(dp[i][j] = dp[i - 1][j]) %= MOD;
			printf("dp[%d][%d] = %lld  dp[%d][%d] = %d\n", i+1, j, dp[i+1][j], i, j, dp[i][j]);
		}
		*/
		int p = lower_bound(all(D), 2 * D[i]) - D.begin();
		rep(j, 5){
			(dp[i + 1][j] += dp[i][j]) %= MOD;
			if(j != 4) (dp[p][j + 1] += dp[i][j]) %= MOD;
		}
	}
	cout << dp[N][4] << endl;
	return 0;
}