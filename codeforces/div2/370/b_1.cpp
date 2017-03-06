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
	int dx = 0, dy = 0;
	rep(i, s.size()){
		if(s[i] == 'L') dx--;
		else if(s[i] == 'R') dx++;
		else if(s[i] == 'U') dy++;
		else if(s[i] == 'D') dy--;
	}
	printf("%d\n", (abs(dx - 0) + abs(dy - 0)) / 2);

	return 0;
}