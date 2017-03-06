#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <stack>
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

static const int NIL = -1;
int n, m, y;

//int color[200010];//繋がってるところに同じidを割り当てる
int year[200010][200010];

void dfs(int v, int w, vector<int> G[]){
	int cnt = 0;
	stack<int> S;
	S.push(v);

	while(!S.empty()){
		int u = S.top(); S.pop();
		rep(i, G[u].size()){
			int v = G[u][i];
			if(year[u][i] <= w && G[u][i] != NIL){
				S.push(v);
				G[u][i] = NIL;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return;
}


int main(void){
	cin  >> n >> m;
	vector<int> G[200010];
	int a, b;
	rep(i, m){
		scanf("%d %d %d", &a, &b, &y);
		G[a].push_back(b);
		G[b].push_back(a);
		year[a][b] = y;
	}

	int q; cin >> q;
	int v, w;
	rep(i, q){
		scanf("%d %d", &v, &w);
		dfs(v, w, G);
	}
	return 0;
}