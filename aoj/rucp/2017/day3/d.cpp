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

int N, M;
int X[5010], Y[5010];
ll T[5010];
int v0, a, b, c;

typedef tuple<ll, int, int> tup;
const int MAX_N = 510;
vector<pair<int, ll> > G[MAX_N];
vector<vector<ll>> dijkstra(int start, int fv){
	//dist[i][j] := start->iまでの移動で, 速度がjの時の体感移動距離の総和の最小値
	vector<vector<ll>> dist(MAX_N, vector<ll>(55, INFF));
	dist[start][fv] = 0;
	priority_queue<tup, vector<tup >, greater<tup > >  que;
	
	que.push(make_tuple(0, fv, start));
	while(!que.empty()){
		ll cost; int v, i;
		tie(cost, v, i) = que.top(); que.pop();
		// printf("%lld %d %d\n", cost, v, i);
		if(dist[i][v] < cost) continue;
		int nv = (a * v + b);
		nv %= c;
		// printf("%lld %d %d nv %d\n", cost, v, i, nv);
		for (auto tmp : G[i]){
			int j = tmp.first; ll time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[j][nv] > dist[i][v] + time * v){//i->j
				dist[j][nv] = dist[i][v] + time * v;
				que.push(make_tuple(dist[j][nv], nv, j));
			}
		}
	}
	return dist;
}

int main(void){
	scanf("%d %d", &N, &M);
	rep(i, M) scanf("%d %d %lld", &X[i], &Y[i], &T[i]);
	rep(i, M) X[i]--, Y[i]--;
	rep(i, M){
		G[X[i]].pb(mp(Y[i], T[i]));
		G[Y[i]].pb(mp(X[i], T[i]));
	}
	scanf("%d", &v0);
	scanf("%d %d %d", &a, &b, &c);
	auto dis = dijkstra(0,v0);
	ll ans = INFF;
	rep(j, 52){
		if(dis[N - 1][j] == INFF) continue;
		// printf("%lld\n", dis[N - 1][j]);
		auto tm = dijkstra(N - 1, j);
		rep(k, 52) chmin(ans, dis[N - 1][j] + tm[0][k]);
		// printf("ans %lld\n", ans);
	}
	printf("%lld\n", ans);
	return 0;
}