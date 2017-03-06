#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<pair<int, int> > a(n);
	rep(i, n){
		int tmp; cin >> tmp;
		a[i] = make_pair(tmp, i + 1);
	}
	sort(a.begin(), a.end());

	rep(i, n / 2){
		printf("%d %d\n", a[i].second, a[n - i - 1].second);
	}
	return 0;
}