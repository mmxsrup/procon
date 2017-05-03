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

int N, G, E;
int p[110];
int a[10010], b[10010];

const int MAX_V = 2010; //必要な頂点数
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

int main(void){
	cin >> N >> G >> E;
	rep(i, G) cin >> p[i];
	rep(i, E) cin >> a[i] >> b[i];
	Flow fw;
	rep(i, E){
		fw.add_edge(a[i], b[i], 1);
		fw.add_edge(b[i], a[i], 1);
	}
	rep(i, G){
		fw.add_edge(p[i], N, 1);
	}
	auto ret = fw.max_flow(0, N);
	printf("%d\n", ret);
	return 0;
}