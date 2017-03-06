#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

#define int long long

const int MAX_N = 200010;
vector<pair<int, int> > G[MAX_N];
vector<int> dijkstra(int start){
	vector<int> dist(MAX_N, INF);
    dist[start] = 0;//dist[i] :=　start->iまでの最短距離
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >  que;
    que.push(make_pair(0, start));
    while(!que.empty()){
        int cost, u, t;//今までにかかった時間 現在の頂点
        cost = que.top().first, u = que.top().second;
        que.pop();
        if(dist[u] < cost) continue;
        for (auto tmp : G[u]){
            int v = tmp.first, time = tmp.second;//隣接する頂点 その頂点まで行く時間
            if(dist[v] > dist[u] + time){//u->v
            	dist[v] = dist[u] + time;
            	que.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

int n, m, t;
int A[200010];
int a[100010], b[100010], c[100010];
signed main(void){
	cin >> n >> m >> t;
	rep(i, n) cin >> A[i];
	rep(i, m){
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
		G[a[i]].pb(mp(b[i], c[i]));
	}
	auto dist1 = dijkstra(0);
	rep(i, MAX_N){
		G[i].clear();
	}
	rep(i, m){
		G[b[i]].pb(mp(a[i], c[i]));
	}
	auto dist2 = dijkstra(0);
	ll ans = 0;
	rep(i, n){
		if(dist1[i] + dist2[i] <= t){
			ll d = (t - dist1[i] - dist2[i]) * A[i];
			chmax(ans, d);
		}
	}
	cout << ans << endl;
	return 0;
}