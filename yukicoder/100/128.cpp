#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	ll n, m; cin >> n >> m;
	ll mai = n / 1000;
	printf("%lld\n", (ll)(mai / m) * 1000);
	return 0;
}