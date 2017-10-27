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

int n;
double m[210];
string large[210], small[210];
map<string, int> ma;
map<int, string> rma;

const int MAX_N = 210;
using TYPE = double; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
vector<TYPE> dijkstra(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 1;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] * time){//u->v
				dist[v] = dist[u] * time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(void) {
	cin >> n;
	rep(i, n) cin >> large[i] >> m[i] >> small[i];
	set<string> s;
	rep(i, n) s.insert(large[i]), s.insert(small[i]);
	int idx = 0;
	for(auto u : s) ma[u] = idx, rma[idx++] = u;
	rep(i, n) {
		G[ma[small[i]]].pb(mp(ma[large[i]], m[i]));
		// G[ma[large[i]]].pb(mp(ma[small[i]], 1. / m[i])); // 逆も作れる
	}

	int start, goal;
	double ans = 0;
	rep(i, idx) {
		auto dist = dijkstra(i);
		rep(j, idx) {
			if(dist[j] == INFF) continue;
			// printf("%f ", dist[j]);
			if(ans < dist[j]) {
				ans = dist[j], start = i, goal = j;
			}
		}
		// printf("\n");
	}
	cout << "1" << rma[goal] << "=" << ans << rma[start] << endl;
	return 0;
}