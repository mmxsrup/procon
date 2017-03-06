#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef long long ll;	
#define rep(i,n) for(int i=0;i<(n);i++)
const int MAX_N = 51;

ll dp[MAX_N];

int main(void){
	int n; cin >> n;
	rep(i, n + 1) dp[i] = 0;
	dp[1] = 1, dp[2] = 2;
	for (int i = 3; i <= n; ++i){
		//漸化式
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
}