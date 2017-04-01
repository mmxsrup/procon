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

int n, d, x;
int p[20][20];
int dp[12][100010];
// dp[i][j] := i番目の株を買った後の所持金がjの時の次の日に手にい入れる金の最大値

int main(void){
	cin >> n >> d >> x;
	rep(i, d)rep(j, n) cin >> p[i][j];
	int ma = x;
	rep(day, d - 1){
		rep(i, 12)rep(j, ma + 1) dp[i][j] = 0;
		dp[0][ma] = 0;
		rep(i, n)REP(j, ma + 1){
			if(j + p[day][i] > ma) dp[i + 1][j] = dp[i][j];
			else dp[i + 1][j] = max(dp[i][j], dp[i + 1][j + p[day][i]] + p[day + 1][i]);
			// printf("dp[%d][%d] = %d\n", i + 1, j, dp[i + 1][j]);
		}
		int tmp = 0;
		rep(i, ma + 1) chmax(tmp, i + dp[n][i]);
		ma = tmp;	
	}
	printf("%d\n", ma);
	return 0;
}