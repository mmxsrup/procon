#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <set>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define INF INT_MAX/3
#define PB push_back
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SEC second
#define SETUP cin.tie(0), ios::sync_with_stdio(false), cout << setprecision(15)
struct input_returnner { 
	int N; input_returnner(int N_ = 0) :N(N_) {}
	template<typename T> operator vector<T>() const { vector<T> res(N); for (auto &a : res) cin >> a; return std::move(res); }
	template<typename T> operator T() const { T res; cin >> res; return res;} 
};
template<typename T> input_returnner in() { return in<T>(); }
input_returnner in() { return input_returnner(); }
input_returnner in(int N) { return std::move(input_returnner(N)); }

void solve();
/// ---template---
class MaxFlow {
	struct Edge {
		int to, cap, rev;
		Edge(int t, int c, int r) :to(t), cap(c), rev(r) {}
	};

public:

	vector<vector<Edge> > G;
	vector<bool > used;

	MaxFlow(int MAX_V) :G(MAX_V), used(MAX_V) {}

	void add_edge(int from, int to, int cap) {
		G[from].push_back(Edge(to, cap, G[to].size()));
		G[to].push_back(Edge(from, 0, G[from].size() - 1));
	}

	int dfs(int v, int t, int f) {
		if (v == t) return f;
		used[v] = true;
		for (int i = 0; i < G[v].size(); ++i) {
			Edge &e = G[v][i];
			if (!used[e.to] and e.cap>0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int max_flow(int s, int t) {
		int flow = 0;
		while (true) {
			fill(ALL(used), false);
			int f = dfs(s, t, 0x3f3f3f3f);
			if (f == 0) return flow;
			flow += f;
		}
	}
};


signed main(void) {
	SETUP;
	solve();
	return 0;
}

void solve() {
	int W = in();
	int N = in();
	vector<int> J = in(N);
	int M = in();
	vector<int> C = in(M);
	vector<bitset<50>> X;
	REP(i, M) {
		int Q = in();
		bitset<50> x;
		REP(j, Q) {
			int k = in(); --k;
			x[k] = true;
		}
		X.push_back(x);
	}
	//N+M+1:start
	//N+M+2:goal
	const int start = N + M + 1;
	const int end = N + M + 2;
	MaxFlow mf(N + M + 3);
	REP(n, N) mf.add_edge(start, n, J[n]);
	REP(m, M) REP(n, N) if (not X[m][n]) mf.add_edge(n, N+m, inf);
	REP(m, M) mf.add_edge(N+m, end, C[m]);

	cout << mf.max_flow(start, end) << endl;
	cout << (mf.max_flow(start, end)>=W?"SHIROBAKO": "BANSAKUTSUKITA") << endl;
}