#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
	long long n; cin >> n;
	long long ans = __gcd(n, n * (n - 1) / 2);
	cout << ans << endl;
	return 0;
}