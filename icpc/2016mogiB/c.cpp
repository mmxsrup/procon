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
	
	int n;
	while(1){
		cin >> n;
		if(n == 0) break;
		vpint xy(n);
		rep(i, n){
			scanf("%d %d", &xy[i].fi, &xy[i].se);
		}
		int sitenx = xy[0].fi;
		int siteny = xy[0].se;

		board[]
		int menseki = 0;
		rep(i, n - 1){
			int hen_len = abs(xy[i + 1].fi - xy[i].fi + xy[i + 1].se - xy[i].se);
			int takasa;
			if(xy[i].fi == xy[i + 1].fi) takasa = xy[i].fi;
			else takasa = xy[i].se;
			menseki += hen_len * takasa / 2;
		}
		
		vpint hen;
		rep(i, n - 1){
			if(xy[i + 1].fi - xy[i].fi > 0){
				while(xy[i + 1] - xy[i] + cnt){

				}
			}
		}
		pint point[4]
		rep(i, n) scanf("%d %d", &point[i].fi, &point[i].se);




	}

	return 0;
}