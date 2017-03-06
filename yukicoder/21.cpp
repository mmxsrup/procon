#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n, k; cin >> n >> k;
	vector<int> num(n);
	rep(i, n) cin >> num[i];
	sort(num.begin(), num.end());
	cout << num[n - 1] - num[0]<< endl;
	return 0;
}