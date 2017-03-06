#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int n;
int v[1010];
int dp[1010][2];

int main(void){
	cin >> n;
	rep(i, n) cin >> v[i];
	rep(i, 1010)rep(j, 2) dp[i][j] = -1;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < 2; ++j){
			if(dp[i][j] == -1) continue;
			if(j == 0){
				dp[i + 1][1] = max(dp[i + 1][1], dp[i][0] + v[i]);
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
			}else{
				dp[i + 1][0] = max(dp[i + 1][0], dp[i][1]);
			}
		}
	}
	int cost, idx;
	vector<int> ans;
	if (dp[n][0] > dp[n][1]){
		cost = dp[n][0];
	}else{
		cost = dp[n][1] - v[n - 1];
		ans.push_back(n);
	}
	// printf("idx %d cost %d\n", idx, cost);
	for (int i = n - 1; i >= 1; --i){
		if(idx == 0){
			if(dp[i][0] == cost){
				idx = 0;
			}else{
				idx = 1;
				cost -= v[i - 1];
				ans.push_back(i);
			}
		}else{
			idx = 0;
		}
	}
	
	reverse(ans.begin(), ans.end());
	printf("%d\n", max(dp[n][0], dp[n][1]));
	rep(i, ans.size()){
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}