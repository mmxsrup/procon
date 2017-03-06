#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()), v.end());//重複消去

	if(v.size() == 1){
		printf("0\n");
		return 0;
	}
	int ans = 1e9;
	rep(i, v.size() - 1){
		ans = min(ans, v[i + 1] - v[i]);
	}
	printf("%d\n", ans);
	return 0;
}