#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n, a; cin >> n >> a;
	vector<int> x(n);
	rep(i, n){
		cin >> x[i];
	}
	sort(x.begin(), x.end());
	
	int ans = 1e9;
	if(n == 1){
		ans = 0; cout << ans << endl;
		return 0;
	}
	if(n == 2){
		ans = min(abs(a - x[1]), abs(a - x[0]));
		cout << ans << endl;
		return 0;
	}

	ans = min(ans, abs(x[n - 1] - a) + x[n - 1] - x[1]);
	ans = min(ans, abs(x[n - 2] - a) + x[n - 2] - x[0]);
	ans = min(ans, abs(a - x[0]) + x[n - 2] - x[0]);
	ans = min(ans, abs(a - x[1]) + x[n - 1] - x[1]);
	cout << ans << endl;
	return 0;
}