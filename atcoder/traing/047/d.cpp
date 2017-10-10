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

const int MAX_N = 1010;
using TYPE = double; // 距離の型を入れる
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

int N;
int x[1010], y[1010], t[1010], r[1010];

int main(void) {
	cin >> N;
	rep(i, N) cin >> x[i] >> y[i] >> t[i] >> r[i];
	if(N == 1) {
		printf("0\n"); return 0;
	}

	rep(i, N)rep(j, N) {
		if(i == j) continue;
		double du = min(t[i], r[j]);
		double dv = min(r[i], t[j]);
		double dist = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
		G[i].pb(mp(j, dist / du)), G[j].pb(mp(i, dist / dv));
	}

	auto dist = dijkstra(0);
	vector<double> v;
	reps(i, 1, N) {
		v.pb(dist[i]);
	}
	sort(all(v)); reverse(all(v));
	double ans = 0;
	// 中継点でぶつかることはない why? 最短経路で行っているはずなので, もしぶつかるようなことがあれば, １秒以上早くいく経路が存在したことになる.
	rep(i, N - 1) {
		chmax(ans, v[i] + i);
	}
	printf("%.9lf\n", ans);
	return 0;
}