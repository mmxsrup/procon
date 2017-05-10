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
// #define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

const int MAX_N = 200010;
vector<pair<int, ll> > G[MAX_N];
vector<pair<int, ll> > rG[MAX_N];

vector<ll> dijkstra(int start){
	vector<ll> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		ll cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
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

vector<ll> rdijkstra(int start){
	vector<ll> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		ll cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : rG[u]){
			int v = tmp.first; ll time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int N, M, T;
ll A[100010];
int a[100010], b[100010], c[100010];

int main(void){
	cin >> N >> M >> T;
	rep(i, N) cin >> A[i];
	rep(i, M){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--; b[i]--;
		G[a[i]].pb(mp(b[i], c[i]));
		rG[b[i]].pb(mp(a[i], c[i]));
	}

	auto d = dijkstra(0);
	auto rd = rdijkstra(0);
	ll ans = 0;
	rep(i, N){
		ll time = d[i] + rd[i];
		// printf("%lld %lld %lld\n", d[i], rd[i], time);
		if(time < T){
			// printf("%lld\n", T - time);
			chmax(ans, A[i] * (T - time));
		}
	}
	printf("%lld\n", ans);
	return 0;
}