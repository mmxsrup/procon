#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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

int dp[100010];//dp[i]ばんめにいるときの最小値

int main(void){
	int n; cin >> n;
	vint a(n);
	rep(i, n) scanf("%d", &a[i]);
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	reps(i, 2, n){
		dp[i] = min(abs(a[i] - a[i - 1]) + dp[i - 1], abs(a[i] - a[i - 2]) + dp[i - 2]);
		//printf("i:%d dp:%d\n", i, dp[i]);
	}
	printf("%d\n", dp[n - 1]);

	return 0;
}