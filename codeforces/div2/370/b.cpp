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
	int d[4];//LRUD
	rep(i, 4) d[i] = 0;
	if(s.size() % 2 == 1){
		printf("-1\n");
		return 0;
	}
	rep(i, s.size()){
		if(s[i] == 'L') d[0]++;
		else if(s[i] == 'R') d[1]++;
		else if(s[i] == 'U') d[2]++;
		else if(s[i] == 'D') d[3]++;
	}

	if(d[0] == d[1] && d[2] == d[3]){
		// printf("ok\n");
		printf("0\n");
		return 0;
	}else if(d[0] == d[1] && d[2] != d[3]){
		printf("%d\n", abs(d[2] - d[3]) / 2);
	}else if(d[0] != d[1] && d[2] == d[3]){
		printf("%d\n", abs(d[1] - d[2]) / 2);
	}else if((d[0] % 2 == 0 && d[1] % 2 == 1) || (d[0] % 2 == 1 && d[1] % 2 == 0)){
		printf("%d\n", (abs(d[0] - d[1]) + abs(d[2] - d[3])) / 2);
	}else{
		int ans = 1e9;
		int tmp = abs(d[0] - d[1]) / 2 + abs(d[2] - d[3]) / 2;
		ans = min(ans, tmp);
		printf("%d\n", ans);
		return 0;
	}

	return 0;
}