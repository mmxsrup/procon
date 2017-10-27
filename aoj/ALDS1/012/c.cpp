#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const long long INFF = 1e18;

const int MAX_N = 11000;
using TYPE = long long; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];

vector<TYPE> A_star(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(1, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		// if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				TYPE h = 1; // ゴールまでの推定値
				// printf("%f\n", h);
				que.push(make_pair(dist[v] + 1e9, v));
			}
		}
	}
	return dist;
}

int main(void) {
	int n; cin >> n;
	rep(q, n) {
		int u, k; cin >> u >> k;
		vector<int> v(k); vector<long long> c(k);
		rep(i, k) cin >> v[i] >> c[i];
		rep(i, k) G[u].push_back(make_pair(v[i], c[i]));
	}
	auto dist = A_star(0);
	rep(i, n) printf("%d %d\n", i, dist[i]);
	return 0;
}