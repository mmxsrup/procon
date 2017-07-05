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


ll xs, ys, xt, yt;
ll N;
double x[1100], y[1100], r[1100];

const int MAX_N = 2000010;
vector<pair<int, double> > G[MAX_N];
vector<double> dijkstra(int start){
	vector<double> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		double cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; double time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}


int main(void) {
	cin >> xs >> ys >> xt >> yt;
	cin >> N;
	x[0] = xs, y[0] = ys, x[N + 1] = xt, y[N + 1] = yt;
	reps(i, 1, N + 1) cin >> x[i] >> y[i] >> r[i];
	rep(i, N + 2)reps(j, i + 1, N + 2){
		auto dist = [](int i, int j) {
			return max((double)0, sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) - (r[i] + r[j]));
		};
		G[i].pb(mp(j, dist(i, j))), G[j].pb(mp(i, dist(i, j)));
	}
	auto ret = dijkstra(0);
	printf("%.9f\n", ret[N + 1]);
	return 0;
}