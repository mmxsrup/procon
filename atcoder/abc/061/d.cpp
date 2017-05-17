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
#define rall(v) (v).rbegin(), (v).rend()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
#define OUT(x) cout << #x << " = " << x << endl; 
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e15;
#define int long long
 
using Weight = int;
using Flow = int;
struct Edge {
    int src, dst;
    Weight weight;
    Flow cap;
    Edge() : src(0), dst(0), weight(0) {}
    Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;
 
void add_edge(Graph &g, int a, int b, Weight w = 1) {
    g[a].emplace_back(a, b, w);
    g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }
 
std::pair<std::vector<Weight>, bool> bellmanFord(const Graph &g, int s) {
    int n = g.size();
    // const Weight inf = std::numeric_limits<Weight>::max() / 8;
    Edges es;
    for (int i = 0; i < n; i++)
        for (auto &e : g[i]) es.emplace_back(e);
    std::vector<Weight> dist(n, INFF);
    dist[s] = 0;
    bool negCycle = false;
    for (int i = 0;; i++) {
        bool update = false;
        for (auto &e : es) {
            if (dist[e.src] != INFF && dist[e.dst] > dist[e.src] + e.weight) {
                dist[e.dst] = dist[e.src] + e.weight;
                update = true;
            }
        }
        if (!update) break;
        if (i > n) {
            negCycle = true;
            break;
        }
    }
    return std::make_pair(dist, !negCycle);
}
 
ll N, M;
ll a[2010], b[2010], c[2010];
signed main(void){
	cin >> N >> M;
	rep(i, M) cin >> a[i] >> b[i] >> c[i];
	rep(i, M) a[i]--, b[i]--;
	Graph v(N);
	rep(i, M){
		v[a[i]].emplace_back(a[i], b[i], -c[i]);
	}
	auto r = bellmanFord(v, 0);
	if(r.se == false){
		printf("inf\n");
	}else{
		printf("%lld\n", -r.fi[N - 1]);
	}
	return 0;
}