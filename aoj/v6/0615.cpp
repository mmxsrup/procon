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
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
#define int long long 
int n;
ll a[4020];
//dp[l][r][isJOI] := [l, r]をすでにとっていて, 次ケーキを取るのがJOIくんの時のJOIくんの最大値
ll dp[4020][4010][2];

signed main(void){
	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n) a[n + i] = a[i];
	rep(i, 4020)rep(j, 4020)rep(k, 2) dp[i][j][k] = -1;
	rep(i, 2 * n) dp[i][i][0] = a[i];

	for (int len = 0; len <= 2 * n; ++len){
		for (int i = 0; i + len < 2 * n; ++i){
			int l = i, r = i + len;
			rep(k, 2){
				if(dp[l][r][k] == -1) continue;
				// printf("%d %d %d\n", l, r, k);
				if(k == 0){//next IOI
					if(1 <= l && r <= 2 * n - 2){
						if(a[l - 1] > a[r + 1]) chmax(dp[l - 1][r][1], dp[l][r][0]);
						else  chmax(dp[l][r + 1][1], dp[l][r][0]);
					}else if(1 <= l){
						chmax(dp[l - 1][r][1], dp[l][r][0]);
					}else if(r <= 2 * n - 2){
						chmax(dp[l][r + 1][1], dp[l][r][0]);
					}
				}else{// next JOI
					if(1 <= l && r <= 2 * n - 2){
						chmax(dp[l - 1][r][0], dp[l][r][1] + a[l - 1]);
						chmax(dp[l][r + 1][0], dp[l][r][1] + a[r + 1]);
					}else if(1 <= l){
						chmax(dp[l - 1][r][0], dp[l][r][1] + a[l - 1]);
					}else if(r <= 2 * n - 2){
						chmax(dp[l][r + 1][0], dp[l][r][1] + a[r + 1]);
					}
				}
			}
		}
	}
	ll ans = 0;
	rep(i, n + 1)rep(j, 2)chmax(ans, dp[i][n + i - 1][j]);
	printf("%lld\n", ans);
	return 0;
}