#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	ll n, k; cin >> n >> k;
	vector<ll> v(n);
	rep(i, n)cin >> v[i];
	rep(i, n){
		if(v[i] == 0){
			printf("%lld\n", n);
			return 0;
		}
	}

	ll now = 1;
	int ans = 0;
	int r = 0;
	for (int l = 0; l < n; ++l){
		for (; r < n; ++r){
			now *= v[r];
			// printf("now %lld l %d  r %d\n", now, l, r);
			if(now <= k){
				ans = max(ans, r - l + 1);
			}else{
				now /= v[l];
				r++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}