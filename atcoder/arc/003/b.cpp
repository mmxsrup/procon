#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<pair<string, string> > ans;
	rep(i, n){
		string tmp; cin >> tmp;
		string d;
		rep(j, tmp.size()){
			d += tmp[tmp.size() - j - 1];
		}
		ans.push_back(make_pair(d, tmp));
	}
	sort(ans.begin(), ans.end());
	rep(i, ans.size()){
		cout << ans[i].second << endl;
	}
	return 0;
}