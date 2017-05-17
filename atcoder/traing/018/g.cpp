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

class strongly_connected_components{
public:
	vector<int> cmp; //cmp[v] := 頂点vが含まれる連結成分がどれなのかを示す番号
	vector<vector<int>> scc, SG;
	int V; // 頂点数
	strongly_connected_components(int n): V(n), G(n), rG(n), cmp(n), used(n){}
	void add_edge(int from, int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}
	int build(){
		fill(used.begin(), used.end(), 0);
		vs.clear();
		for (int i = 0; i < G.size(); ++i){
			if(!used[i]) dfs(i);
		}
		fill(used.begin(), used.end(), 0);

		int k = 0;
		for (int i = vs.size() - 1; i >= 0; --i){
			if(!used[vs[i]]){
				scc.push_back(vector<int>());
				rdfs(vs[i], k++);
			}
		}
		SG.resize(scc.size());
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < G[v].size(); i++) {
				if (cmp[v] < cmp[G[v][i]]) {
					SG[cmp[v]].push_back(cmp[G[v][i]]);
				}
			}
 		}
		for (int i = 0; i < SG.size(); i++) {
			sort(SG[i].begin(), SG[i].end());
			SG[i].erase(unique(SG[i].begin(), SG[i].end()), SG[i].end());
		}
		return k; //sccの数
	}
private:
	vector<vector<int> > G, rG;
	vector<int> used, vs;
	void dfs(int curr){
		used[curr] = true;
		for(auto next : G[curr]){
			if(!used[next]) dfs(next);
		}
		vs.push_back(curr);
	}
	void rdfs(int curr, int k){
		used[curr] = true;
		scc[k].push_back(curr);
		cmp[curr] = k;//頂点vに対して、k番目と強連結成分であること入れる
		for(auto next : rG[curr]){
			if(!used[next]) rdfs(next, k);
		}
	}
};

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
std::vector<int> tsort(const Graph &g) {
    int n = g.size();
    enum { YET, VISITED, DONE };
    std::vector<int> res, flg(n, YET);
    static const std::function<bool(int)> dfs = [&](int v) {
        flg[v] = VISITED;
        for (auto &e : g[v]) {
            int w = e.dst;
            if (flg[w] != DONE && (flg[w] == VISITED || !dfs(w))) return false;
        }
        flg[v] = DONE;
        res.push_back(v);
        return true;
    };
    for (int i = 0; i < n; ++i)
        if (flg[i] == YET && !dfs(i)) return {};
    std::reverse(res.begin(), res.end());
    return res;
}

int n, m, k;
char c[310];
int a[1010], b[1010];
string dp[310][310];

int main(void){
	cin >> n >> m >> k;
	rep(i, n) cin >> c[i];
	rep(i, m) cin >> a[i] >> b[i];
	rep(i, m) a[i]--, b[i]--;

	strongly_connected_components sc(n);
	rep(i, m) sc.add_edge(a[i], b[i]);

	int num = sc.build();

	vector<string> v;
	rep(i, num){
		// printf("i %d\n", i);
		vector<char> tmpc;
		rep(j, sc.cmp.size())if(sc.cmp[j] == i) tmpc.pb(c[j]);
		sort(all(tmpc));
		string ss;
		for(auto u : tmpc) ss += u;
		// cout << ss << endl;
		v.pb(ss);
	}

	// printf("cmp\n");
	// rep(i, sc.cmp.size())printf("cmp %d %d\n", i, sc.cmp[i]);

	Graph g(num);
	rep(i, num){
		for(auto to : sc.SG[i]){
			// printf(" %d -> %d\n", i, to);
			g[i].emplace_back(i, to, 0);
		}
	}
	auto ord = tsort(g);

	rep(i, 310)rep(j, 310) dp[i][j] = "{";
	// reverse(all(ord));
	rep(i, 310) dp[i][0] = "";
	rep(i, num)for(to : sc.SG[i]){
		rep(len, k + 1){
			if(dp[i][j - len] == "{") continue;
			string d = v[to].substr(0, len);
			chmin(dp[to][len], dp[i][j - len] + d);
		}
	}

	vector<string> ans;
	rep(i, num){
		ans.pb(dp[i][k]);
	}
	sort(all(ans));
	if(ans.size() == 0) printf("-1\n");
	else cout << ans[0]  << endl;
	return 0;
}