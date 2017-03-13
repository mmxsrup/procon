#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;
/*

std::vector<std::vector<std::string>> catalogUpdate(std::vector<std::vector<std::string>> catalog, std::vector<std::vector<std::string>> updates) {
	map<string, vector<string>> sett;
	std::vector<std::vector<std::string>> ans;
	rep(i, catalog.size()){
		// cout << "i " << catalog[i][0] << endl;
		reps(j, 1, catalog[i].size()){
			sett[catalog[i][0]].pb(catalog[i][j]);
		}
	}
	rep(i, updates.size()){
		// cout << "up " << updates[i][1] << endl;;
		sett[updates[i][0]].pb(updates[i][1]);
	}
	for(auto u : sett){
		auto ma = u.fi;
		// cout << "ma " << ma << endl;
		auto v = u.se;
		sort(all(v));
		 v.erase(std::unique(v.begin(), v.end()), v.end());
		// v.erase(eall(v), v.end());
		 /*
		for(auto tt : v){
			cout << tt << " ";
		}
		*/
		// printf("\n");
		auto it = v.begin();         // 先頭のイテレータを取得
		it = v.insert(it,ma);  //先頭に200を追加
		ans.pb(v);
	}
	return ans;
}

int main(void){
	auto k = catalogUpdate({{"Books","Classics","Fiction"}, 
 {"Electronics","Cell Phones","Computers","Ultimate item"}, 
 {"Grocery","Beverages","Snacks"}, 
 {"Snacks","Chocolate","Sweets"}, 
 {"root","Books","Electronics","Grocery"}}, {{"Books","Classics","Fiction"}, 
 {"Electronics","Cell Phones","Computers","Ultimate item"}, 
 {"Grocery","Beverages","Snacks"}, 
 {"Snacks","Chocolate","Sweets"}, 
 {"root","Books","Electronics","Grocery"}});
	for(auto u : k){
		for(auto v : u){
		cout << v << " ";
		}
		printf("\n");
	}
	return 0;
}

int toAndFroNaive(int a, int b, int t) {
	len = abs(b - a);
	t %= (2 * len);
	if(t <= len) return a + (b - a) / abs(b - a) * t;
	else{
		t -= len;
		return b - (b - a) / abs(a - b) * t;
	}
}
*/

int countVisibleTowerPairs(std::vector<int> position, std::vector<int> height) {
	int ret = 0;
	for (int i = 0; i < position.size(); ++i){
		for (int j = i + 1; j < position.size(); ++j){
			double d = (height[j] - height[i]) / (position[j] - [position[i]]);
			flag = true;
			for (int k = 0; k < position.size(); ++k){
				if(!(position[i] <= position[k] and position[k] <= position[j])) continue;
				if(height[i] + d * (position[k] - position[i]) <= height[k]){
					flag = false;
					break;
				}
			}
			if(flag) ret++;
		}
	}
	return ret;
}
