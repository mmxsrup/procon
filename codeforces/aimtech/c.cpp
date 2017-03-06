#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	bool flag = false;
	rep(i, s.size()){
		if(s[i] != 'a'){
			s[i]--; flag = true;
		}else if(s[i] == 'a' && flag){
			break;
		}
		if(i == s.size() - 1 && !flag){
			if(s[s.size() - 1] == 'a') s[s.size()- 1] = 'z';
			else s[s.size()]--;
		}
	}
	cout << s << endl;
	return 0;
}