#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int w, h; cin >> w >> h;
	string c; cin >> c;
	int cnt;
	if(c == "B") cnt = 0;
	else cnt = 1;
	rep(i, h){
		string tmp;
		if(cnt % 2 == 0){
			int f = 0;
			rep(j, w){
				if(f % 2 == 0) tmp += 'B';
				else tmp += 'W';
				f++;
			}
		}else{
			int f = 1;
			rep(j, w){
				if(f % 2 == 0) tmp += 'B';
				else tmp += 'W';
				f++;
			}
		}
		cout << tmp << endl;
		cnt++;
	}
}