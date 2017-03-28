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
 
string s;
string t = "yahoo";
// dp[i][j] := sのi文字目までと, tのj文字目までを一致させるときの最小値
int dp[100010][10];
 
int main(void){
	cin >> s;
	rep(i, 100010)rep(j, 10) dp[i][j] = INF;
	rep(i, 100010) dp[i][0] = i;
	rep(i, 10) dp[0][i] = i;
	for (int i = 1; i <= s.size(); ++i){
		for (int j = 1; j <= 10; ++j){
			// printf("i %d j %d\n", i, j);
			// printf("%d %d \n", dp[i - 1][(j - 1) % 5], dp[i - 1][j % 5]);
			// printf("%d %d\n", dp[i][(j - 1) % 5], dp[i][j % 5]);
			chmin(dp[i][j % 5], dp[i][(j - 1) % 5] + 1); // insert
			chmin(dp[i][j % 5], dp[i - 1][j % 5] + 1); // delete
			if(s[i - 1] == t[j - 1]) chmin(dp[i][j % 5], dp[i - 1][(j - 1) % 5]); // replace
			else chmin(dp[i][j % 5], dp[i - 1][(j - 1) % 5] + 1); //replace
			// printf("%d %d \n", dp[i - 1][(j - 1) % 5], dp[i - 1][j % 5]);
			// printf("%d %d\n", dp[i][(j - 1) % 5], dp[i][j % 5]);
		}
	}
	rep(i, s.size() + 1) {
		rep(j, 5){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	cout << dp[s.size()][0]<< endl;
	return 0;
}