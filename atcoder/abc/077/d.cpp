#include <bits/stdc++.h>
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

const int MAX_N = 200010;
using TYPE = ll; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
vector<TYPE> dijkstra(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}


int K;

int main(void) {
	cin >> K;
	reps(i, 1, K) {
		reps(j, 1, 10) {
			G[i].pb(mp((i + j) % K, j));
			// printf("%d %d %d\n", i, (i + j) % K, j);
		}
		G[i].pb(mp((i * 10) % K, 0));
	}
	auto dist = dijkstra(1);
	printf("%lld\n", dist[0] + 1);
	return 0;
}