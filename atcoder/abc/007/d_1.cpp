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

//dp[i][j] := dp[i][j][k][l] := i桁目まで見て, j=1ならすでにAより小さい数になっていて,
//k=1なら4を使用してい, l=1なら9を使用しているような数の総数
ll dp[20][2][2][2];
ll solve(string s){
	rep(i, 20)rep(j, 2)rep(k, 2)rep(l, 2) dp[i][j][k][l] = 0;
	dp[0][0][0][0] = 1;
	rep(i, s.size())rep(j, 2)rep(k, 2)rep(l, 2){
		if(dp[i][j][k][l] == 0) continue;
		if(j == 0){
			rep(num, s[i] - '0'){
				if(num == 4) dp[i + 1][1][1][l] += dp[i][j][k][l];
				else if(num == 9) dp[i + 1][1][k][1] += dp[i][j][k][l];
				else dp[i + 1][1][k][l] += dp[i][j][k][l];
			}
			if(s[i] == '4') dp[i + 1][0][1][l] += dp[i][j][k][l];
			else if(s[i] == '9') dp[i + 1][0][k][1] += dp[i][j][k][l];
			else dp[i + 1][0][k][l] += dp[i][j][k][l];

		}else{
			rep(num, 10){
				if(num == 4) dp[i + 1][1][1][l] += dp[i][j][k][l];
				else if(num == 9) dp[i + 1][1][k][1] += dp[i][j][k][l];
				else dp[i + 1][1][k][l] += dp[i][j][k][l];
			}
		}
	}
	ll ans4 = 0, ans9 = 0, ans49 = 0;
	rep(j, 2)rep(l, 2) ans4 += dp[s.size()][j][1][l];
	rep(j, 2)rep(k, 2) ans9 += dp[s.size()][j][k][1];
	rep(j, 2) ans49 += dp[s.size()][j][1][1];
	// printf("%d %d %d\n", ans4, ans9, ans49);
	return ans4 + ans9 - ans49;
}
int main(void){
	ll A, B; cin >> A >> B; A--;
	ll ret = solve(to_string(B)) - solve(to_string(A));
	cout << ret << endl;
	return 0;
}