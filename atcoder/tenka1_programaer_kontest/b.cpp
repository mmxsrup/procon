#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int dp[110][55][110];//
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
				//全部でi + 1枚目
				printf("%d %d\n", i, j);
				if(s[i + 1] == '('){

					//変更
					if(i + 1 > j * 2) continue;
					dp[i + 1][j][i + 1] = min(dp[i][j][k] + i + 1 - k + 1, dp[i + 1][j][i + 1]);
					printf("2 dp[%d][%d][%d] = %d\n", i + 1, j, i + 1, dp[i + 1][j][i + 1]);

					//そのまま
					if(i + 1 > (j + 1) * 2) continue;
					dp[i + 1][j + 1][k] = min(dp[i][j][k], dp[i + 1][j + 1][k]);
					printf("1 dp[%d][%d][%d] = %d\n", i + 1, j + 1, k, dp[i + 1][j + 1][k]);

				}else if(s[i + 1] == ')'){
					//そのまま
					if(i + 1 > j * 2) continue;
					dp[i + 1][j][k] = min(dp[i][j][k], dp[i + 1][j][k]);
					printf("3 dp[%d][%d][%d] = %d\n", i + 1, j, k, dp[i + 1][j][k]);
					//変更
					if(i + 1 > (j + 1) * 2) continue;
					// printf("k %d\n", k);
					dp[i + 1][j + 1][i + 1] = min(dp[i][j][k] + i + 1 - k + 1, dp[i + 1][j + 1][i + 1]);
					printf("4 dp[%d][%d][%d] = %d\n", i + 1, j + 1, i + 1, dp[i + 1][j + 1][i + 1]);

				}
			}
		}
	}

	int ans = INF;
	for (int i = 0; i < n; ++i){
		ans = min(ans, dp[n - 1][n / 2][i]);
	}
	printf("%d\n", ans);
	return 0;
}