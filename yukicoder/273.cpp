#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	vector<int> ans;//見つけた回分の長さを入れていく
	for (int i = 1; i <= s.size(); ++i){
		for (int l = 0; l < s.size(); ++l){
			string tmp = s.substr(l, i);

			string hantenn;
			for (int j = tmp.size() - 1; j >= 0; --j){
				hantenn += tmp[j];
			}
			if(tmp == hantenn){
				ans.push_back(tmp.size());
			}
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	for(auto u : ans){
		if(u == s.size()) continue;
		else{
			cout << u << endl;
			return 0;
		}
	}
}
