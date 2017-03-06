#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	//中央値を計算
	if(v.size() % 2 == 0){
		printf("%d\n", v[v.size() / 2 - 1]);
	}else{
		printf("%d\n", v[v.size() / 2]);
	}
	return 0;
}