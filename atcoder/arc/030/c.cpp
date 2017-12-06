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

int n, m, k;
char c[310];
int a[1010], b[1010];

class strongly_connected_components{
public:
	vector<vector<int> > G, rG;
	vector<int> used, vs;
	vector<int> cmp; //cmp[v] := 頂点vが含まれる連結成分がどれなのかを示す番号
	strongly_connected_components(int n): G(n), rG(n), cmp(n), used(n){}
	void add_edge(int from, int to){
		G[from].push_back(to);
		rG[to].push_back(from);
	}
	int scc(){
		fill(used.begin(), used.end(), 0);
		vs.clear();
		for (int i = 0; i < G.size(); ++i){
			if(!used[i]) dfs(i);
		}
		fill(used.begin(), used.end(), 0);

		int k = 0;
		for (int i = vs.size() - 1; i >= 0; --i){
			if(!used[vs[i]]){
				rdfs(vs[i], k++);
			}
		}
		return k; //sccの数
	}
private:
	void dfs(int curr){
		used[curr] = true;
		for(auto next : G[curr]){
			if(!used[next]) dfs(next);
		}
		vs.push_back(curr);
	}
	void rdfs(int curr, int k){
		used[curr] = true;
		cmp[curr] = k;//頂点vに対して、k番目と強連結成分であること入れる
		for(auto next : rG[curr]){
			if(!used[next]) rdfs(next, k);
		}
	}
};

vector<int> G[310];
string memo[310];
//dp[i][j] := i番目の連結成分までを見て, 文字列の長さがjとなるときの最小文字列
string dp[310][310];
bool used[310]; // 同じ頂点を何度も調べないようにTLE対策

void dfs(int u, int pre) {
	used[u] = true;
	for(auto v : G[u]) {
		if(u == pre) continue;
		rep(j, k + 1)rep(len, memo[v].size() + 1) {
			// 頂点uまでで, 長さがjの辞書順最小文字列に, 頂点vの文字列を前から長さlen使ったときの文字列
			string tm = dp[u][j] + memo[v].substr(0, len);
			if(tm.size() > k) continue;
			if(dp[v][j + len] > tm) dp[v][j + len] = tm;
		}
		dfs(v, u);
	}
}

int main(void) {
	cin >> n >> m >> k;
	rep(i, n) cin >> c[i];
	rep(i, m) cin >> a[i] >> b[i];
	rep(i, m) a[i]--, b[i]--;

	strongly_connected_components scc(n);
	rep(i, m) scc.add_edge(a[i], b[i]);
	vector<int> tG[310];
	rep(i, m) tG[a[i]].pb(b[i]);

	int size = scc.scc(); // sccの成分の数

	// sccを行った後のDAGを出している
	set<int> st[310];
	rep(u, n) for(auto v : tG[u]) if(scc.cmp[u] != scc.cmp[v]) st[scc.cmp[u]].insert(scc.cmp[v]);
	rep(u, 310) for(auto v : st[u]) G[u].pb(v);
	
	rep(i, 310) { // i番目の連結成分
		vector<char> t;
		rep(j, n){ // 頂点番号
			if(scc.cmp[j] == i) t.pb(c[j]);
		}
		sort(all(t));
		string s;
		for(auto u : t) s += u;
		memo[i] = s;
	}
	// rep(i, size) cout << i << " " << memo[i] << endl;
	

	rep(i, 310)rep(j, 310) dp[i][j] ="{";
	rep(i, size) rep(j, memo[i].size() + 1) {
		if(j <= k) dp[i][j] = memo[i].substr(0, j);
	}
	rep(i, size) if(!used[i]) dfs(i, -1); // iを始点にして

	string ans = "{"; // 辞書順最大
	rep(i, size) if(ans > dp[i][k]) ans = dp[i][k];
	if(ans == "{") printf("-1\n");
	else cout << ans << endl;
	return 0;
}