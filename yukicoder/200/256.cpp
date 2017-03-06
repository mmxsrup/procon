#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	vector<int> v;
	rep(i, s.size()){
		v.push_back(s[i] - '0');
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	rep(i, v.size()){
		printf("%d", v[i]);
	}
	printf("\n");
	return 0;
}