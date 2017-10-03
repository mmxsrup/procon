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

const int MAX_N = 2510;
using TYPE = ll; // 距離の型を入れる
vector<pair<ll, TYPE> > G[MAX_N];
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

int N, M, R, T;
int main(void) {
	scanf("%d %d %d %d", &N, &M, &R, &T);
	rep(i, M) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		G[a].pb(mp(b, c)), G[b].pb(mp(a, c));
	}

	ll ans = 0;
	rep(i, N) {
		auto dist = dijkstra(i);
		// printf("dist\n");
		// for(auto u : dist) printf("%d ", u);
		// printf("\n");
		vector<double> vr, vt; // うさぎ かめ
		rep(j, N) {
			if(i == j) continue;
			// printf("dist %d\n", dist[j]);
			vr.push_back((double)dist[j] / (double)R);
			vt.push_back((double)dist[j] / (double)T);
		}
		sort(all(vr)), sort(all(vt));
		// printf("r\n");
		// for(auto k : vr) printf("%f ", k);
		// printf("\n");
		for(auto k : vt) { // かめ
			// printf("t %f\n", k);
			ll cnt = (N - 1) - (lower_bound(all(vr), k) - vr.begin());
			// printf("cnt %d\n", cnt);
			ans += cnt;
		}
	}
	printf("%lld\n", ans);
	return 0;
}