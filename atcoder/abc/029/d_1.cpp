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

string N;

ll dp[20][2][20];

int main(void){
	cin >> N;
	rep(i, 20)rep(j, 2)rep(k, 20) dp[i][j][k] = 0;
	dp[0][0][0] = 1;
	rep(i, N.size())rep(j, 2)rep(k, 20){
		rep(num, 10){
			if(j == 1){
				if(num == 1)dp[i + 1][1][k + 1] += dp[i][j][k];
				else dp[i + 1][1][k] += dp[i][j][k];
			}else{
				if(num == (N[i] - '0')){
					if(num == 1) dp[i + 1][0][k + 1] += dp[i][j][k];
					else dp[i + 1][0][k] += dp[i][j][k];
				}else if(num < (N[i] - '0')){
					if(num == 1) dp[i + 1][1][k + 1] += dp[i][j][k];
					else dp[i + 1][1][k] += dp[i][j][k];
				}
			}
		}
	}
	ll ans = 0;
	rep(j, 2)rep(k, 20){
		ans += k * dp[N.size()][j][k];
	}
	printf("%lld\n", ans);
	return 0;
}