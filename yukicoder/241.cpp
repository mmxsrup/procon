#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> tmp(n);
	rep(i, n) tmp[i] = i;//適当
	bool flag = true; int cnt = 0;
	while(flag && cnt < 10000){
		cnt++; flag = false;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				if(i == j) continue;
				if(a[i] == tmp[i] || a[j] == tmp[j]){
					swap(tmp[i], tmp[j]);
				}
			}
		}
		rep(i, n){//　チェック
			if(a[i] == tmp[i]){
				flag = true; break;
			}
		}
		if(!flag){
			rep(i, n) printf("%d\n", tmp[i]);
			return 0;
		}
	}
	printf("-1\n");
}
