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
set<pair<int, int> > memo;
set<pair<int, int> > e;
vector<int> G[20010];
int main(void){
	cin >> n >> m;
	rep(i, m){
		int x, y; cin >> x >> y;
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
		hen.push_back(make_pair(x, y));
		memo.insert(make_pair(x, y));
		memo.insert(make_pair(y, x));
	}

	/*
		  0
		/   \
	  u1 	 v1   
		\    |
		 u2-v2

	*/

	/*
	for(auto d : hen){
		int u1 = d.first, v1 = d.second;
		// printf("u1 %d v1 %d\n", u1, v1);
		for(auto u2 : G[u1]){
			for(auto v2 : G[v1]){
				// printf("u2 %d v2 %d\n", u2, v2);
				if(u2 == v1) continue;
				if(u1 == v2) continue;
				if(u2 == v1) continue;
				// printf("u2 %d v2 %d\n", u2, v2);

				for (int p = 0; p < n; ++p){
					if(p == u1 || p == u2 || p == v1 || p == v2) continue;
					if(memo.count(make_pair(u2, p)) && memo.count(make_pair(v2, p))){
						if(u1 == 0 || u2 == 0 || v1 == 0 || v2 == 0 || p == 0){
							// printf("ok u1 %d v1 %d\n", u1, v1);
							// printf("ok u2 %d v2 %d\n", u2, v2);
							// printf("p %d\n", p);
							printf("YES\n");
							return 0;
						}
					}
				}
			}
		}
	}
	*/

	//u1, v1 を探す
	for(auto d : hen){
		int u2 = d.first, v2 = d.second;
		for(auto u1 : G[u2]){
			for(auto v1 : G[v2]){
				if(u1 == u2 || u1 == v2 || v1 == u2 || u1 == 0 || v1 == 0) continue;
				e.insert(make_pair(u1, v1));
				e.insert(make_pair(v1, u1));
			}
		}
	}

	for(auto tu1 : G[0]){
		for(auto tv1 : G[0]){
			if(tu1 == tv1) continue;
			if(e.count(make_pair(tu1, tv1))){
				printf("YES\n");
				return 0;
			}
		}
	}

	/*
	for(auto u1 : G[0]){
		for(auto v1 : G[0]){
			if(u1 == v1 || u1 == 0 || v1 == 0) continue;
			for(auto u2 : G[u1]){
				if(G[u2].size() == 0) continue;
				for(auto v2 : G[v1]){
					if(u2 == v2 || u2 == 0 || v2 == 0 || v1 == u2 || u1 == v2) continue;
					if(memo.count(make_pair(u2, v2))){
						printf("YES\n");
						return 0;
					}
				}
			}
		}
	}
	*/
	printf("NO\n");
	return 0;
}