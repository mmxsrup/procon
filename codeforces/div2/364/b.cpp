#include <iostream>
#include <cstdio>
#include <set>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	ll n, m; cin >> n >> m;
	set<ll> x, y;
	rep(i, m){
		ll tx, ty; cin >> tx >> ty;
		x.insert(tx);
		y.insert(ty);
		//行、列が減ると小さくなる
		printf("%I64d ", (ll)((n - x.size()) * (n - y.size())));
	}
	printf("\n");
	return 0;
}