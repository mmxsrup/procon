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

int main(void){
	int v, e; cin >> v >> e;
	strongly_connected_components scc(v);
	rep(i, e){
		int s, t; cin >> s >> t;
		scc.add_edge(s, t); // s->t
	}
	scc.scc();
	int q; cin >> q;

	rep(i, q){
		int u, v; cin >> u >> v;
		if(scc.cmp[u] == scc.cmp[v]){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
	return 0;
}