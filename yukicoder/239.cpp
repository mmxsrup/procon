#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)


bool flag[110];
int main(void){
	rep(i, 110) flag[i] = true;
	int n; cin >> n;
	rep(i, n){
		rep(j, n){
			string s; cin >> s;
			if(i == j) continue;
			if(s != "nyanpass") flag[j] = false;
		}
	}

	int num, cnt = 0;
	rep(i, n){
		if(flag[i]){
			num = i + 1;
			cnt++;
		}
	}
	if(cnt == 1) printf("%d\n", num);
	else printf("-1\n");
	return 0;
}