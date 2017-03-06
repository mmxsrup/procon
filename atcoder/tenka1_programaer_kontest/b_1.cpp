#include <iostream>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//dp[i][j][k] := s[i]文字目まで見て、'('がj文字で、最後に文字を反転したのが
//s[k]文字目の時のコストの最小値
int dp[110][55][110];
const int INF = 1e9;
int main(void){
	rep(i, 110)rep(j, 55)rep(k, 110) dp[i][j][k] = INF;

	string s; cin >> s;
	int n = s.size();
	if(s[0] == '(')dp[0][1][0] = 0;
	else dp[0][1][0] = 1;
	for (int i = 0; i < n - 1; ++i){
		for (int j = 0; j <= n / 2; ++j){
			for (int k = 0; k < n; ++k){
				if(dp[i][j][k] == INF)  continue;
				if(s[i + 1] == '('){
					//変更
					if(i + 1 > j * 2) continue;
					dp[i + 1][j][i + 1] = min(dp[i][j][k] + i + 1 - k + 1, dp[i + 1][j][i + 1]);
					//そのまま
					if(i + 1 > (j + 1) * 2) continue;
					dp[i + 1][j + 1][k] = min(dp[i][j][k], dp[i + 1][j + 1][k]);
				}else if(s[i + 1] == ')'){
					//そのまま
					if(i + 1 > j * 2) continue;
					dp[i + 1][j][k] = min(dp[i][j][k], dp[i + 1][j][k]);
					//変更
					if(i + 1 > (j + 1) * 2) continue;
					dp[i + 1][j + 1][i + 1] = min(dp[i][j][k] + i + 1 - k + 1, dp[i + 1][j + 1][i + 1]);
				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i){
		ans = min(ans, dp[n - 1][n / 2][i]);
	}
	cout << ans << endl;
	return 0;
}