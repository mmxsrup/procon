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
	int ans[30];
	rep(i, 30) ans[i] = 0;
	rep(i, s.size()){
		ans[s[i] - 'a']++;
	}
	rep(i, 26){
		if(ans[i] % 2 == 1){
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}