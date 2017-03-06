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

int dp[101][4];
const int inf = -1e8;
int main(void){
	int n; cin >> n;
	vector<int>	v(n + 1);
	rep(i, n) scanf("%d", &v[i + 1]);
	v[0] = 0;

	rep(i, 101)rep(j, 4) dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= 2; ++j){//yasumi
			if(v[i] == 0 && dp[i - 1][j] != inf){
				dp[i][0] = max(dp[i - 1][j] + 1, dp[i][0]);

			}else if(v[i] == 1 && dp[i - 1][j] != inf){//konntesut
				if(j == 0 || j == 2) dp[i][1] = max(dp[i - 1][j], dp[i][1]);
				else dp[i][1] = max(dp[i - 1][j] + 1, dp[i][1]);
				// printf("1 dp[%d][1] = %d\n",i, dp[i][1]);

			}else if(v[i] == 2 && dp[i - 1][j] != inf){//zimu
				if(j == 0 || j == 1 ) dp[i][2] = max(dp[i - 1][j], dp[i][2]);
				else dp[i][2] = max(dp[i - 1][j] + 1, dp[i][2]);
				// printf("2 dp[%d][2] = %d\n", i, dp[i][2]);

			}else if(v[i] == 3 && dp[i - 1][j] != inf){//zimu konntesut
				if(j == 1) dp[i][2] = max(dp[i - 1][j], dp[i][2]);
				if(j == 2) dp[i][1] = max(dp[i - 1][j], dp[i][1]);
				// printf("3 dp[%d][3] = %d\n", i, dp[i][3]);
			}
		}
	}
	int ans = 0;
	rep(i, 4){
		ans = max(ans, dp[n][i]);
	}
	printf("%d\n", ans);
	return 0;

}