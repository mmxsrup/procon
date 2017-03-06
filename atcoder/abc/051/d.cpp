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

const int MAX_N = 110;
vector<pair<int, int> > G[MAX_N];
vector<int> dijkstra(int start, int goal){//スタートとゴールを逆に
	vector<long long> dist(MAX_N, INF);
	vector<int> pre(MAX_N, -1);//pre[i] := iの前の頂点
    dist[start] = 0;//dist[i] :=　start->iまでの最短距離
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
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
            	pre[v] = u;
            	que.push(make_pair(dist[v], v));
            }else if(dist[v] == dist[u] + time){//辞書順最小
            	pre[v] = min(pre[v], u);
            }
        }
    }
    //経路復元
    vector<int> path;
    int s = start, t = goal;
	for (; t != s; t = pre[t]) path.push_back(t);
	path.push_back(s);
	reverse(path.begin(), path.end());
	return path; //start-> * -> goal startからgoalまでの最短経路(辞書順最小)
}

int n, m;
int main(void){
	cin >> n >> m;
	rep(i, m){
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		G[a].pb(mp(b, c));
		G[b].pb(mp(a, c));
	}

	set<pair<int, int> > se;
	rep(i, n)rep(j, n){
		if(i == j) continue;
		auto ret = dijkstra(i, j);
		rep(i, ret.size() - 1){
			se.insert(mp(min(ret[i], ret[i + 1]), max(ret[i], ret[i + 1])));
		}
	}
	printf("%d\n", m - se.size());
}