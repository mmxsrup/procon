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

//答えが1つ大きくなる問題.
int a[1010], b[1010], c[1010];
int main(void){
    int N, M; cin >> N >> M;
    set<pair<int, int>> nokori;
    rep(i, M){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        nokori.insert(mp(a[i], b[i])), nokori.insert(mp(b[i], a[i]));
    }
    rep(i, M)G[a[i]].pb(mp(b[i], c[i])), G[b[i]].pb(mp(a[i], c[i]));
    // set<pair<int, int>> se;
    rep(s, N)rep(t, N){
        if(s == t)continue;
        auto d = dijkstra(s, t);
        rep(i, d.size() - 1){
            nokori.erase(mp(d[i], d[i + 1]));
            nokori.erase(mp(d[i + 1], d[i]));
            // se.insert(mp(min(d[i], d[i + 1]), max(d[i], d[i + 1])));
            // se.insert(mp(d[i], d[i + 1]));
        }
    }
    // printf("%d\n", M - (int)se.size()); 
    // printf("nokori %d\n", nokori.size());
    printf("%d\n", (int)nokori.size() / 2);
    return 0;
}