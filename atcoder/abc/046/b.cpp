#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	string s; cin >> s;
	string ans;
	int n = s.size();

	rep(i, n){
		if(s[i] == '0') ans += '0';
		else if(s[i] == '1') ans += '1';
		else if(s[i] == 'B'){
			ans.pop_back();
		}
	}
	cout << ans << endl;
	return 0;
}