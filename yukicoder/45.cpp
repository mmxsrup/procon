#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	int dp[1001][2];
	dp[0][0] = 0;
	dp[0][1] = v[0];
	dp[1][0] = v[0];
	dp[1][1] = v[1];
	reps(i, 2, n){
		dp[i][0] = max(dp[i - 1][1], dp[i - 2][1]);
		dp[i][1] = max(dp[i - 1][0] + v[i], dp[i - 2][0] + v[i]);
	}
	int ans = max(dp[n - 1][0], dp[n - 1][1]);
	printf("%d\n", ans);
	return 0;
}