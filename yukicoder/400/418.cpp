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
	bool flag = true; int ans = 0;
	rep(i, s.size()){
		if(s[i] == 'm' && s[i + 1] == 'i'){
			flag = true; i++;
		}

		if(flag && s[i] == 'n'){
			ans++;
			flag = false;
		}
	}
	printf("%d\n", ans);
	return 0;
}