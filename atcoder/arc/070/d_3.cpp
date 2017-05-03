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

int N, K;
int a[5010];
int dp[5010][5010];
int rdp[5010][5010];

int main(void){
	cin >> N >> K;
	rep(i, N) cin >> a[i];

	dp[0][0] = 0;
	rep(i, N){
		rep(j, 5001){
			if(dp[i][j] == 0) continue;
			dp[i + 1][j] = 1;
			dp[i + 1][min(5000, j + a[i])] = 1;
		}
	}
	dp[N][0] = 0;
	for (int i = n; i >= 1; ++i){
		rep(j, 5001){
			if(dp[i][j] == 0) continue;
			dp[i - 1][j] = 1;
			dp[i - 1][min(5000, j + a[i])] = 1;
		}
	}
	rep(i, N){
		vector<int> v;
		rep(j, 5001)rep(k, 5001) if(dp[i - 1][j] && dp[i + 1][k]) v.pb(j + k);
	}
	return 0;
}