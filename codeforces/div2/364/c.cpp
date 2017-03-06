#include <iostream>
#include <cstdio>
#include <map>
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; string s;
	cin >> n >> s;
	map<char, int> m;
	rep(i, n) m[s[i]] = 0;

	int ans = 1e9;
	int l = 0;
	for (int r = 0; r < n; ++r){//右をすすめる
		m[s[r]]++;
		bool flag = true;
		for(auto t : m){
			if(t.second == 0) flag = false;
		}
		
		while(l <= r){//追い越し
			if(flag == false) break;
			ans = min(ans, r - l + 1);

			//条件を満たしてるときは、左を進める
			m[s[l]]--;
			l++;
			for(auto t : m){
				if(t.second == 0){
					flag = false;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}