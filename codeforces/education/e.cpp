#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	int x, y; cin >> x >> y;
	long long now = 0;
	long long time = 0;
	int lim;
	rep(i, n){
		if(n < pow(2, i)) lim = i;
	}
	lim++;
	// printf("%d\n", lim);
 	long long ans = 1e9;
	for (int i = lim; i >= 0 ; --i){
		long long cnt = x; long long now = 1;
		for (int j = 0; j < i; ++j){
			now *= 2;
			cnt += y;
		}
		if(now > n) continue;

		cnt += (n - now) * x;
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}