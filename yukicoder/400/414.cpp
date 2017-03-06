#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	ll m; cin >> m;
	for (ll i = 2; i < sqrt(m) + 1; ++i){
		if(m % i == 0){
			printf("%lld %lld\n", i, m / i);
			return 0;
		}
	}
	printf("1 %lld\n", m);
	return 0;
}