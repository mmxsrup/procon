#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	while(1){
		int n, m; cin >> n >> m;
		if(n == 0 && m == 0) return 0;
		vector<int> p(n);
		rep(i, n) cin >> p[i];
		p.push_back(0);//矢を使わないを入れる
		int ans = 0;
		//計算量(n^4)
		rep(i, n + 1)rep(j, n + 1)rep(k, n + 1)rep(l, n + 1){
			int tmp = p[i] + p[j] + p[k] + p[l];
			if(tmp <= m) ans = max(ans, tmp);
		}
		printf("%d\n", ans);
	}
	return 0;
}