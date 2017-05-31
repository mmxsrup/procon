#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int N, M;
//G[(c1, u)][(c2, v)] := c1を通ってu1に来て, c2を通ってvに行く時のコスト
map<pair<int, int>, pair<int, int>> G;
map<pair<int, int> int> dist;

vector<int> dijkstra(int start){
	dist[mp(-1, start)] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>> >, greater<pair<int, pair<int, int>> > >  que;
	que.push(mp(0, mp(-1, start)));
	while(!que.empty()){
		int cost, c, u;//コスト どの路線から 現在の頂点
		auto tm = que.top(); q.pop();
		cost = tm.fi, c = tm.se.fi, u = tm.se.se;
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; ll time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(void){
	scanf("%d %d", &N, &M);
	rep(i, M){
		int p, q, c; scanf("%d %d %d", &p, &q, &c);
		p--, q--;
		G[mp(c, p)][mp(c, q)] = 0;
		G[mp(c, q)][mp(c, p)] = 0;
		G[mp(-1, p)][mp(-1, q)] = 1;
		G[mp(-1, q)][mp(-1, p)] = 1;
		G[mp(c, p)][mp(-1, p)] = 0;
		G[mp(c, q)][mp(-1, q)] = 0;
	}
	dijkstra();
}