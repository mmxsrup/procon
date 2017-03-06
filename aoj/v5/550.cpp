#include <iostream>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

//dp[i][j][k] :=　(お菓子の長さがiでAさんの文がjの時で次ににkさんがお菓子をもらう
//時の切断する時の秒数が最小の時間) (k==0:A k==1:B)
int dp[10010][5010][2];
int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n - 1) cin >> v[i];
	rep(i, 10010)rep(j, 5010)rep(k, 2)dp[i][j][k] = INF;

	dp[0][0][0] = 0;
	dp[0][0][1] = 0;
	//配るdp
	for (int i = 0; i < n; ++i){
		for (int j = 0; j <= n / 2; ++j){
			for (int k = 0; k < 2; ++k){
				if(dp[i][j][k] == INF) continue;
				//お菓子を切らない時
				if(k == 0){
					dp[i + 1][j + 1][k] = min(dp[i + 1][j + 1][k], dp[i][j][k]);
				}else{
					dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				}
				//お菓子を切る時
				if(k == 0){
					dp[i + 1][j + 1][1] = min(dp[i + 1][j + 1][1], dp[i][j][k] + v[i]);
				}else{
					dp[i + 1][j][0] = min(dp[i + 1][j][0], dp[i][j][k] + v[i]);
				}
			}
		}
	}

	int ans = INF;
	rep(k, 2){
		ans = min(ans, dp[n][n / 2][k]);
	}
	cout << ans << endl;
}