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

//dp[i][j][k][l] := i番目の桁までみて, j=1のときSより小さく,
//k=1のとき前の桁が数字1で, これまでの12が出てきた回数がl回 となる数字の総数

ll dp[16][2][2][10];

ll solve(string s){
	rep(i, 16)rep(j, 2)rep(k, 2)rep(l, 10) dp[i][j][k][l] = 0;
	dp[0][0][0][0] = 1;
	rep(i, s.size())rep(j, 2)rep(k, 2)rep(l, 10){
		if(dp[i][j][k][l] == 0) continue;
		if(j == 1){ // sより小さい
			if(k == 1){
				rep(num, 10){
					if(num == 2)dp[i + 1][1][0][l + 1] += dp[i][j][k][l];
					else dp[i + 1][1][0][l] += dp[i][j][k][l];
				}
			}else{
				rep(num, 10){
					if(num == 1) dp[i + 1][1][1][l] += dp[i][j][k][l];
					else dp[i + 1][1][0][l] += dp[i][j][k][l];
				}
			}
		}else{ // s以下
			if(k == 1){ // 1つ前が1
				rep(num, s[i] - '0' + 1){
					if(num < s[i] - '0'){ //小さい
						if(num == 2) dp[i + 1][1][0][l + 1] += dp[i][j][k][l];
						else if(num == 1) dp[i + 1][1][1][l] += dp[i][j][k][l];
						else dp[i + 1][1][0][l] += dp[i][j][k][l];
					}else{
						if(num == 2) dp[i + 1][0][0][l + 1] += dp[i][j][k][l];
						else if(num == 1) dp[i + 1][0][1][l] += dp[i][j][k][l];
						else dp[i + 1][1][0][l] += dp[i][0][k][l];
					}
				}
			}else{ // 1つ前が1以外
				rep(num, s[i] - '0' + 1){
					if(num < s[i] - '0'){ //小さい
						if(num == 1) dp[i + 1][1][1][l] += dp[i][j][k][l];
						else dp[i + 1][1][0][l] += dp[i][j][k][l];
					}else{
						if(num == 1) dp[i + 1][0][1][l] += dp[i][j][k][l];
						else dp[i + 1][1][0][l] += dp[i][0][k][l];
					}
				}
			}
		}
	}
	ll ret = 0;
	rep(j, 2)rep(k, 2)rep(l, 10){
		ret += dp[(int)s.size()][j][k][l] * l;
	}
}

int main(void){
	ll A, B; cin >> A >> B;
	A--;
	printf("%lld\n", solve(to_string(B)) - solve(to_string(A)));
}