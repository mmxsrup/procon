#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	ll sum = 1e9;
	for (int i = -100; i <= 100 ; ++i){
		ll tmp = 0;
		rep(j, n){
			tmp += pow((i - v[j]), 2);
		}
		sum = min(tmp, sum);
	}
	cout << sum << endl;
	return 0;
}