#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

long long dp[101][21];
int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) scanf("%d", &v[i]);
	dp[0][v[0]] = 1;
	rep(i, n){//iは何個目を見ているか
		for (int j = 0; j <= 20; ++j){
			if(j + v[i] <= 20){
				dp[i][j + v[i]] += dp[i - 1][j];
			}
			if(0 <= i - v[i]){
				dp[i][j - v[i]] += dp[i - 1][j];
			}
		}
	}
	printf("%lld\n", dp[n - 1][v[n - 1]]);
	return 0;
}