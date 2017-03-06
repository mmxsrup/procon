#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;

int n, m;
vector<pair<int, int> > hen;
// set<pair<int, int> > memo;
vector<int> e[20010];// e[u2][u1] := 0 -> u1 -> u2
vector<int> G[20010];
int main(void){
	cin >> n >> m;
	rep(i, m){
		int x, y; cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
		hen.push_back(make_pair(x, y));
		// memo.insert(make_pair(x, y));
		// memo.insert(make_pair(y, x));
	}

	/*
		  0
		/   \
	  u1 	 v1   
		\    |
		 u2-v2

	*/

	for(auto u1 : G[0]){
		for(auto u2 : G[u1]){
			if(u1 != u2 && u2 != 0){
				e[u2].push_back(u1);
			}
		}
	}

	for(auto d : hen){
		int u2 = d.first, v2 = d.second;
		if(u2 == 0 || v2 == 0) continue;
		for(auto u1 : e[u2]){
			for(auto v1 : e[v2]){
				if(u1 != v1 && u1 != v2 && v1 != u2 && u2 != v2){
					printf("YES\n");
					return 0;
				}
			}
		}

	}

	printf("NO\n");
	return 0;
}