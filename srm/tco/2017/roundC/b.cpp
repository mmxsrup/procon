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

const int MAX_N = 2010;

class EllysWordCoins{
public:
	map<string, int> ma;
	// vector<pair<int, int>> G[1010];
	// vector<vector<pair<int, int>>> G;
	vector<pair<int, int> > graph[MAX_N];
	int dp[MAX_N];
	int dfs(int p, int pre, int cost, int goal){
		// printf("%d %d %d %d\n", p, pre, cost, goal);
		if(p == goal) return dp[p];

		int ret = INF;
		for(auto next : graph[p]){
			auto b = dfs(next.fi, p, cost + next.se , goal);
			chmin(ret, b);
		}
		return dp[p] = ret;
	}
	

	int getCost(vector <string> market, string S, string G){
		vector<pair<string, int>> u, v;
		set<string> se;
		
		for(auto s : market){
			
			int p = 0;
			rep(i, s.size())if(s[i] == ' ') p = i;
			string d1 = s.substr(0, p), d2 = s.substr(p + 1);
			se.insert(d1), se.insert(d2);
			int cd1 = 0, cd2 = 0;
			for(auto c : d1) cd1 += c - 'A' + 1;
			for(auto c : d2) cd2 += c - 'A' + 1;
			u.pb(mp(d1, cd1)), v.pb(mp(d2, cd2));
			
			
		}
	
		int idx = 0;
		for(auto d : se){
			ma[d] = idx;
			idx++;
		}
		rep(i, market.size()){
			int start = ma[u[i].fi];
			int goal = ma[v[i].fi];
			int cost = v[i].se - u[i].se;

			graph[start].pb(make_pair(goal, cost));
			// G[1].pb(mp(1, 1));
		}
		return dfs(ma[S], -1, 0, ma[G]);
	}
};

int main(void){
	EllysWordCoins we;
	auto d = we.getCost({"TOPCODER OPEN", "SOURCE CODE", "CHALLENGE POINTS", "POINTS OPEN", "QUAL ROUND",
 "ROUND CHALLENGE", "QUAL FUN", "FUN TOPCODER", "OPEN FINAL", "OPEN SOURCE", "CODE FINAL"}, 
 "QUAL", "FINAL");
	printf("%d\n", d);
	return 0;
}