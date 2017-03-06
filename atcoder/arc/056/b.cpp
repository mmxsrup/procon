//bitDP
//dp[mask] [0, 2^N - 1](maskは頂点の部分集合)　１がいるで0がいないてきな
//ans = dp[2^n - 1](全ている)
//dp[0] = 0
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

bool color[200000];
int n, m , s;
vector<int> G[200000];

bool dfs(int fine){
	stack<int> S;
	S.push(s);
	while(!S.empty()){
		int u= S.top(); S.pop();
		rep(i, G[u].size()){
			int v = G[u][i];
			if(v == find){
				color[fine] == false;
				return true;
			}
			if(color[v] == true){
				S.push(v);
			}
		}
	}
	return false;
}

int main(void){
	rep(i, 200000) color[i] = true;
	cin >> n >> m >> s;
	s--;
	rep(i, m){
		int u, v; scanf("%d %d", &u, &v);
		u--; v--;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	vector<int> memo;

	rep(i, n){
		if(dfs(i) == true) memo.push_back(i);
	}
	sort(all(memo));
	rep(i, memo.size()) printf("%d\n", memo[i]);
	return 0;
}