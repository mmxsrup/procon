#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int a[5];
	int memo[110];
	rep(i, 110) memo[i] = 0;
	int sum = 0;
	rep(i, 5){
		int t; cin >> t;
		sum += t;
		memo[t]++;
	}

	int ans = sum;
	for (int i = 100; i >= 1; --i){
		if(memo[i] == 2){
			ans = min(ans, sum - i * 2);			
		}else if(memo[i] >= 3){
			ans = min(ans, sum - i * 3);
		}
	}

	printf("%d\n", ans);
	return 0;
}