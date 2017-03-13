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

int n, m;
int c[100010], b[100010], a[100010];
vector<pair<int, int>> G[10010];
ll dist[10010][2000];

const int MAX_N = 10010;
typedef tuple<int, int, int> tup;
void dijkstra(int start){
	rep(i, 10010)rep(j, 2000)dist[i][j] = INF;
	dist[start][0] = 0;
	priority_queue<tup, vector<tup>, greater<tup > >  que;
	que.push(make_tuple(0, 0, start));
	while(!que.empty()){
		auto d = que.top(); que.pop();
		int cost, time, u;
		tie(cost, time, u) = d;
		// printf("%d %d u : %d\n", cost, time, u);
		if(dist[u][time] < cost) continue;
		if(time >= 1999) continue;
		for (auto tmp : G[u]){
			int v = tmp.fi;
			if(tmp.se == 0){
				// printf("v1: %d\n", v);
				if(dist[v][time] > dist[u][time] + 1){
					dist[v][time] = dist[u][time] + 1;
					que.push(make_tuple(dist[v][time], time, v));
				}
			}else{
				// printf("v0: %d\n", v);
				if(dist[v][time + 1] > dist[u][time] + time + 1){
					dist[v][time + 1] = dist[u][time] + time + 1;
					que.push(make_tuple(dist[v][time + 1], time + 1, v));
				}
			}
		}
	}
}

int main(void){
	cin >> n >> m;
	rep(i, m) cin >> c[i] >> a[i] >> b[i];
	rep(i, m){
		G[a[i]].pb(mp(b[i], c[i]));
		G[b[i]].pb(mp(a[i], c[i]));
	}
	dijkstra(0);
	rep(i, n){
		int ans = INF;
		rep(j, 2000){
			chmin(ans, dist[i][j]);
		}
		printf("%d\n", ans);
	}
	return 0;
}