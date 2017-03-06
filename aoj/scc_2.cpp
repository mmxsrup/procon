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
	strongly_connected_components(const vector<vector<int> > &g, const vector<vector<int> > &rg, int n): G(g), rG(rg), cmp(n), used(n){
		exec();
	}
	int exec(){
		printf("k\n");
		/*
		rep(i, G.size()){
			sort(all(G[i]));
			sort(all(rG[i]));
		}
		*/
		/*
		rep(i, G.size()){
			for(auto t : G[i]){
				printf("%d->%d\n", i, t);
			}
		}
		rep(i, rG.size()){
			for(auto t : rG[i]){
				printf("rg %d->%d\n", i, t);
			}
		}
		*/
		
		fill(used.begin(), used.end(), 0);
		for (int i = 0; i < G.size(); ++i){
			if(!used[i]) dfs(i);
		}
		fill(used.begin(), used.end(), 0);
		int k = 0;

		for (int i = vs.size() - 1; i >= 0; --i){
			if(!used[vs[i]]){
				printf("vs %d\n", vs[i]);
				rdfs(vs[i], k++);
			}
		}
		return k; //sccの数
	}
	int operator[](int i){//連結成分の番号を返す
        return cmp[i];
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
		printf("curr %d k %d\n", curr, k);
		used[curr] = true;
		cmp[curr] = k;//頂点vに対して、k番目と強連結成分であること入れる
		printf("cmp[%d] = %d\n", curr, cmp[curr]);
		printf("%d rGsize=%d\n", curr, rG[curr].size());
		for(auto next : rG[curr]){
			if(!used[next]) rdfs(next, k);
		}
	}
};


int main(void){
	int v, e; cin >> v >> e;
	vector<vector<int> > g(v), rg(v);
	rep(i, e){
		int s, t; cin >> s >> t;
		g[s].pb(t);
		rg[t].pb(s);
	}

	strongly_connected_components scc(g, rg, v);
	rep(i, v){
        printf("cmp_%d %d\n", i, scc[i]);
    }
	printf("k\n");
	int q; cin >> q;

	rep(i, q){
		int u, v; cin >> u >> v;
		if(scc[u] == scc[v]){
			printf("1\n");
		}else{
			printf("0\n");
		}
	}
	return 0;
}