#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


//dp[i][j] := i番目の寿司まで見て、j=0の時i番目はとらず、j=1の時はi番目を取った
//場合のおいしさがはいる
int dp[1010][2];

int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	rep(i, 110)rep(j, 2) dp[i][j] = 0;
	dp[0][0] = 0; dp[0][1] = v[0];
	for (int i = 1; i < n; ++i){
		for (int j = 0; j < 2; ++j){
			if(j == 0){//i番目の寿司を取らない
				//i - 1番目の寿司は取ることも取らないことも可
				dp[i][j] = max(dp[i][j], max(dp[i - 1][0], dp[i - 1][1]));
			}else{//i番目の寿司を取る
				//i - 1番目の寿司を取ることはできない
				dp[i][j] = max(dp[i][j], dp[i - 1][0] + v[i]);
			}
		}
	}
	int ans, now; vector<int> narabi;
	if(dp[n - 1][0] > dp[n - 1][1]){
		ans = dp[n - 1][0];
		now = 0;
	}else{
		ans = dp[n - 1][1];
		now = 1;
		narabi.push_back(n);//1originで追加
	}
	printf("%d\n", ans);

	rep(i, n)rep(j, 2){
		printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
	}
	

	for (int i = n - 2; i >= 0; --i){
		if(now == 0){//i + 1回目にとってない
			if(dp[i][1] + v[i] == dp[i + 1][0]){//i回目に取る
				now = 1;
				narabi.push_back(i + 1);
			}else if(dp[i][0] == dp[i + 1][0]){//i回目に取らない
				now = 0;
			}
		}else{//i + 1回目に取っている
			if(dp[i][0] + v[]== dp[i + 1][1]){
				now = 0;
			}
		}
	}
	
	reverse(narabi.begin(), narabi.end());
	for(auto u : narabi){
		printf("%d ", u);
	}
	printf("\n");
	return 0;
}