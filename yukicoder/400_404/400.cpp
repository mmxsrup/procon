#include <iostream>
#include <cstring>
using namespace std;

int main(void){
	string s, ans;
	cin >> s;
	for (int i = s.size() - 1; i >= 0; --i){
		if(s[i] == '>') ans += '<';
		else ans += '>';
	}
	cout << ans << endl;
	return 0;
}