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

	vector<bool> flagh(h, false);
	rep(i, h){
		rep(j, w){
			if(s[i][j] == '*'){
				flag[i] = true;
			}
		}
	}

	vector<bool> flagw(w, false);
	rep(i, w){
		rep(j, h){
			if(s[j][i] == '*'){
				flagw[i] = true;
			}
		}
	}

	
	printf("YES\n");
	printf("%d %d\n", );

	return 0;
}