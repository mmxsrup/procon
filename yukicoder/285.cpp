#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	long long d; cin >> d;
	d *= 108;
	double ans;
	string s = to_string(d);
	int n = s.size();
	rep(i, n - 2){
		cout << s[i];
	}
	cout << "." << s[n - 2] << s[n - 1] << endl;
	return 0;
}