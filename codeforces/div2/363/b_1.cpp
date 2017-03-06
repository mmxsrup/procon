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
	int h, w; scanf("%d %d", &h, &w);
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int x, y;
	int cnt = 0;

	vector<int> numh(h, 0);
	rep(i, h){
		rep(j, w){
			if(s[i][j] == '*'){
				numh[i]++;
				cnt++;
			}
		}
	}
	int maxi = 0;
	int maxh;
	rep(i, h){
		if(numh[i] > maxi){
			maxi = numh[i];
			maxh = i;
		}
	}
	printf("%d %d\n", maxi, maxh);

	bool flag = false;
	for (int j = 0; j < w; ++j){
		int now = 0;
		rep(k, w) if(s[maxh][k] == '*')now++;
		if(s[maxh][j] == '*') now--;
		if(now  + maxi == cnt){
			// printf("%d %d %d\n", i, j, now);
			x = j + 1; y = maxh + 1;
			printf("YES\n");
			printf("%d %d\n", y, x);
			flag = true;
			return 0;
		}
	}

	if(flag == false){
		printf("NO\n");
	}

	return 0;
}