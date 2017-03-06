#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

string d[] = {"A", "B", "X", "Y"};
int main(void){
	int n; cin >> n;
	string s; cin >> s;
	int ans = 1e9;
	rep(i, 4)rep(j, 4)rep(k, 4)rep(l, 4){
		string L = d[i] + d[j];
		string R = d[k] + d[l];
		int cnt = 0;//ボタンを押した回数

		for (int p = 0; p < n; ++p){
			if(p == n - 1){
				cnt++; break;
			}
			if(s.substr(p, 2) == L || s.substr(p, 2) == R){
				p++;//１文字飛ばす
				cnt++;
			}else{
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}
