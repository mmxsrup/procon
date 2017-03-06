#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
typedef vector<int> vint;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; scanf("%d", &n);
	string s; cin >> s;
	vint v(n);
	rep(i, n) scanf("%d", &v[i]);
	int ans = 1e9;
	for (int i = 0; i < n - 1; ++i){
		if(s[i] == 'R' && s[i + 1] == 'L'){
			ans = min(ans, (v[i + 1] - v[i]) / 2);
		}
	}
	if(ans == 1e9)printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}