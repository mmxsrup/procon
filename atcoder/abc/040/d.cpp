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

static const int NIL = -1
int n, m, y;
vctor<int> V[200010];
int color[200010];//繋がってるところに同じidを割り当てる
int year[200010];

void dfs(int r, int c){
	stack<int> S;
	S.push(r);
	color[r] = c;//id付与
	while(!S.empty()){
		int u = S.top(); S.pop();
		rep(i, G[u].size() i++){
			int v = G[u][i];
			if(color[v] == NIL){
				color[v] = c;
				S.push(v);
			}
		}
	}
}


void assignColor(){
	int id = 1;
	rep(i, n) color[i] = NIL;
	rep(i, n) if(color[i] == NIL) dfs(i, id++);
}

int main(void){
	cin  >> n >> m;
	rep(i, m){
		scanf("%d %d %d", &a, &b, &y);
		G[a].push_back(b);
		G[b].push_back(a);
		year[i] = y;
	}

	cin >> q;
	rep(i, q){
		
	}
	return 0;
}