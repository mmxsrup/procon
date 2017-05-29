#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
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

int main(void){
	string a;
	vector<string> s;
	while(cin >> a) s.push_back(a);

	int k = s.size();
	while(1){
		bool f = false;
		for (int i = 0; i < k - 2; ++i) {
			printf("i %d\n", i);
			if(s[i] == "not" && s[i + 1] == "not" && s[i + 2] != "not"){
				// printf("i %d\n", i);
				s.erase(s.begin() + i);
				s.erase(s.begin() + i);
				k -= 2;
				f = true;
				break;
			}
		}
		if(!f)break;
	}
	// printf("k\n");
	// for (auto &u : s) cout << u << " ";
	rep(i, s.size()){
		if(i != s.size()) cout << s[i] << " ";
		else cout << s[i] << endl;
	}
	printf("\n");
	return 0;
}