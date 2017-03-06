#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	ll n, a; cin >> n >> a;
	vector<ll> x(n);
	rep(i, n){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	ll ans = 1e9;
	if(x[0] <= a && a <= x[n - 1] && n >= 3){
		ans = min(ans, abs(x[n - 1] - a) + x[n - 1] - x[1]);
		ans = min(ans, abs(x[n - 2] - a) + x[n - 2] - x[0]);
		ans = min(ans, abs(a - x[0]) + x[n - 2] - x[0]);
		ans = min(ans, abs(a - x[1]) + x[n - 1] - x[1]);
	}
	if(a < x[0]){
		// printf("2\n");
		ans = min(ans, x[n - 2] - a);
	}
	if(x[n - 1] < a){
		// printf("3\n");
		ans = min(ans, a - x[1]);
	}
	cout << ans << endl;
	return 0;
}