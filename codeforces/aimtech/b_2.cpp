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
	sort(x.begin(), x.end());
	rep(i, n){
		cin >> x[i];
	}
	ll ans = 1e9;
	if(x[0] <= a && a <= x[n - 1]){
		if(x[1] <= a && a <= x[n - 2]){
			printf("ok\n");
			if(x[n - 1] - a <= a - x[0]){
				ans = min(ans, x[n - 1] - a + x[n - 1] - x[1]);
				
			}else{
				ans = min(ans, abs(x[n - 2] - a) + x[n - 2] - x[0]);
		
			}
		}else if(x[1] <= a){
			printf("1\n");
			ans = min(ans, x[n - 2] - x[0]);
			// continue;
		}else{
			printf("2\n");
			ans = min(ans, x[n - 1] - x[1]);
			// continue;
		}
	}

	//ここから下おk
	if(a < x[0]){
		// printf("2\n");
		ans = min(ans, abs(x[n - 2] - a));
	}
	if(x[n - 1] < a){
		// printf("3\n");
		ans = min(ans, abs(a - x[1]));
	}
	cout << ans << endl;
	return 0;
}