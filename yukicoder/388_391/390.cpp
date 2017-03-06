#include <iostream>
#include <algorithm>
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

int dp[1000000];

int main(void){
	int n; cin >> n;
	rep(i, 1000000) dp[i] = 0;
	vector<int> x(n);
	rep(i, n){
		scanf("%d", &x[i]);
	}
	sort(all(x));
	rep(i, n) dp[x[i]] = 1;
	
	reps(i, 1, 1000000){
		if(dp[i] == 0) continue;
		for (int j = 2 * i; j <= 1000000; j += i){
			if(dp[j] < 1) continue;//先に１を入れることで集合を表すフラグとしても使える
			dp[j] = max(dp[j], dp[i] + 1);
		}
	}
	/*
	rep(i, 100){
		if(dp[i] != 0){
			printf("i%d dp%d\n", i, dp[i]);
		}
	}
	*/
	int ans = 0;
	rep(i, n){
		ans = max(dp[x[i]], ans);
	}
	printf("%d\n", ans);
	
	return 0;
}