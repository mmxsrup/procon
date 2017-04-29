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
int a[80010], b[80010], c[80010], t[80010];
vector<tuple<int, int, int> > G[40010];

//ll dist[40010][1000000010]; //dist[i][j] := i番目の頂点まで色がjの時の最小コスト
map<int, ll> dist[40010];

using tup = tuple<ll, int, int>;
void dijkstra(int start){
    priority_queue<tup, vector<tup>, greater<tup>> que;//cost i j
    dist[start][1] = 0;
    que.push(make_tuple(0, start, 1));
    while(!que.empty()){
        ll cost; int u, color;
        tie(cost, u, color) = que.top(); que.pop();
        if(dist[u][color] < cost) continue;
        if(u == N - 1) break;
       	for(auto tmp : G[u]){
       		int v, nc, nt; tie(v, nc, nt) = tmp;
       		ll addcost = abs(nc - color) + nt;
       		if(!dist[v].count(nc) || dist[v][nc] > cost + addcost){
       			dist[v][nc] = cost + addcost;
       			que.push(make_tuple(cost + addcost, v, nc));
       		}
       	}
    }
}

int main(void){
	scanf("%d %d", &N, &M);
	rep(i, M) scanf("%d %d %d %d", &a[i], &b[i], &c[i], &t[i]);
	rep(i, M) a[i]--, b[i]--;
	rep(i, M){
		G[a[i]].pb(make_tuple(b[i], c[i], t[i])), G[b[i]].pb(make_tuple(a[i], c[i], t[i]));
	}
	dijkstra(0);
	ll ans = INFF;
	for(auto u : dist[N - 1]) chmin(ans, u.se);
	printf("%lld\n", ans);
	return 0;
}