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


const int MAX_V = 3010; //必要な頂点数
struct Flow{
	struct edge{
		int to, cap, rev;
	};
	vector<edge> G[MAX_V];//隣接リスト
	bool used[MAX_V];
 
	void add_edge(int from, int to, int cap){
		G[from].push_back((edge){to, cap, (int)G[to].size()});//from -> to
		G[to].push_back((edge){from, 0, (int)G[from].size() - 1});//to -> from
	}
	//増加パスを探す
	int dfs(int v, int t, int f){
		if(v == t) return f;
		used[v] = true;
		for (int i = 0; i < G[v].size(); ++i){
			edge &e = G[v][i];
			if(!used[e.to] && e.cap > 0){
				int d = dfs(e.to, t, min(f, e.cap));
				if(d > 0){
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	//sからtへの最大流
	int max_flow(int s, int t){
		int flow = 0;
		while(1){
			memset(used, 0, sizeof(used));
			int f = dfs(s, t, INF);
			if(f == 0) return flow;
			flow += f;
		}
	}
};

int N, M;
int X[1010], Y[1010];
int S, T;
int main(void) {
	scanf("%d %d", &N, &M);
	rep(i, M) scanf("%d %d", &X[i], &Y[i]);
	rep(i, M) X[i]--, Y[i]--;
	scanf("%d %d", &S, &T);
	S--, T--;
	set<pair<int, int>> rev;
	map<pair<int, int>, int> ma;
	Flow fw;
	rep(i, M) fw.add_edge(X[i], Y[i], 1), fw.add_edge(Y[i], X[i], 1);
	rep(i, M) rev.insert(mp(Y[i], X[i]));
	rep(i, M) ma[make_pair(Y[i], X[i])] = i;

	int ret = fw.max_flow(S, T);

/*
	int memo[310][310] = {-1}; // 残っているcap
	rep(i, MAX_V) for(auto& u : fw.G[i]) memo[i][u.to] = u.cap;

	set<int> ans;
	rep(i, M) {
		if(memo[Y[i]][X[i]] == 0) ans.insert(i);
	}
*/

	set<int> ans;
	rep(i, MAX_V)for(auto& e : fw.G[i]){
		if(e.cap == 0 && rev.count(mp(i, e.to))) ans.insert(ma[make_pair(i, e.to)]);
	}
	
	printf("%d\n", ret);
	printf("%d\n", ans.size());
	for(auto u : ans) printf("%d\n", u + 1);

	return 0;
}
