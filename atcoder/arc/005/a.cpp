#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	int ans = 0;
	rep(i, n){
		string s; cin >> s;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		if(i == n - 1){
			if(s == "takahashikun.")ans++;
		}else{
			if(s == "takahashikun")ans++;
		}

	}
	cout << ans << endl;
	return 0;
}