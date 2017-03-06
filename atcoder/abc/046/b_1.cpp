#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	string ans;
	rep(i, s.size()){
		if(s[i] == '0') ans += '0';
		else if(s[i] == '1') ans += '1';
		else{
			if(!ans.empty()) ans.pop_back();//空文字でなければ
		}
	}
	cout << ans << endl;
	return 0;
}