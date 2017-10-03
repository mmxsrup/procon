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

map<string, int> city2num;
set<int> LPG;

vector<pair<int, int>> G[6010];
int dist[6010][2010]; // dist[i][j] := 頂点iまで残りLPGがjで来た時の最短距離
using tup = tuple<int, int, int>;

void dijkstra(int start, int cap){
	rep(i, 6010)rep(j, 2010) dist[i][j] = INF;
	cap *= 10;
	dist[start][cap] = 0;
	priority_queue<tup, vector<tup>, greater<tup> >  que; // 距離 頂点 残りのLPG
	que.push(make_tuple(0, start, cap));
	while(!que.empty()){
		int cost, u, lpg;
		tie(cost, u, lpg) = que.top(); que.pop();
		if(dist[u][lpg] < cost) continue;
		for (auto& tmp : G[u]){
			int v = tmp.first, di = tmp.second;
			int nlpg = lpg - di;
			int ncost = cost + di;
			if(nlpg < 0) continue;
			if(LPG.count(v)) {
				/*
				for (int i = nlpg; i <= cap; ++i){ これだとTLE(9.0s)
					if(dist[v][i] > ncost) {
						dist[v][i] = ncost;
						que.push(make_tuple(ncost, v, i));
					}
				}
				*/
				if(dist[v][cap] > ncost) {
					dist[v][cap] = ncost;
					que.push(make_tuple(ncost, v, cap));
				}
			}else{
				if(dist[v][nlpg] > ncost) {
					dist[v][nlpg] = ncost;
					que.push(make_tuple(ncost, v, nlpg));
				}
			}
		}
	}
}


string c1[6010], c2[6010];
int d[6010];
string s[6010];
int main(void) {
	while(1){
		city2num.clear(); LPG.clear();
		rep(i, 6010) G[i].clear();

		int N, M, cap; scanf("%d %d %d", &N, &M, &cap);
		if(N == 0 && M == 0 && cap == 0) break;
		string src, dest; cin >> src >> dest;

		rep(i, N) cin >> c1[i] >> c2[i] >> d[i];
		rep(i, M) cin >> s[i];

		set<string> city;
		rep(i, N) city.insert(c1[i]), city.insert(c2[i]);
		int cnt = 0;
		for(auto& u : city) {
			city2num[u] = cnt++;
		}
		rep(i, M) LPG.insert(city2num[s[i]]);

		rep(i, N) G[city2num[c1[i]]].pb(mp(city2num[c2[i]], d[i])), G[city2num[c2[i]]].pb(mp(city2num[c1[i]], d[i]));
		int ns = city2num[src], nd = city2num[dest];

		dijkstra(ns, cap);
		ll ans = INF;
		rep(i, cap * 10 + 1) chmin(ans, dist[nd][i]);
		if(ans != INF)printf("%lld\n", ans);
		else printf("-1\n");
	}
	return 0;
}