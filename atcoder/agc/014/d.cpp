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
// #define fi first
#define to first
// #define se second
// template<typename T> using Graph = vector<vector<T>>;
#define cost second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

int n;
bool used[100005];
int a[100010], b[100010];
vector<pair<int, int>> tr[100010];
vector<int> G[100010];

pair<int, int> dfs1(int s, int d) {
  used[s] = true;
  pair<int, int> res = {s, d};
  for (auto p: tr[s]) {
    if (used[p.to]) continue;
    auto tp = dfs1(p.to, d + p.cost);
    if (tp.cost > res.cost) res = tp;
  }
  return res;
}
 
int dfs2(int s) {
  used[s] = true;
  int res = 0;
  for (auto p: tr[s]) {
    if (used[p.to]) continue;
    res = max(res, dfs2(p.to) + p.cost);
  }
  return res;
}
 
int diameter() {
  auto p = dfs1(0, 0);
  rep(i, n) used[i] = false;
  return dfs2(p.to);
}

int main(void){
	cin >> n;
	if(n == 2){
		printf("Second\n");
		return 0;
	}
	rep(i, n - 1) cin >> a[i] >> b[i];
	rep(i, n - 1) a[i]--, b[i]--;
	rep(i, n - 1){
		G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);
	}	
	rep(i, n - 1){
		tr[a[i]].pb(mp(b[i], 1)), tr[b[i]].pb(mp(a[i], 1));
	}
	bool flag = false;
	int N = n;
	rep(i, N){
		int cnt = 0;
		for(auto u : G[i]){
			if(G[u].size() == 1) cnt++;
		}
		if(cnt >= 2) flag = true;
	}
	

	rep(i, N){
		int cnt = 0;
		for(auto u : G[i]){
			if(G[u].suze() > 1) cnt++;
			else if(G[u].size() == 1) break;
		}
		if(cnt >= 2) flag = true;
	}
	
	// int d = diameter();
	// if(d % 2 == 0) flag = true;
	if(!flag) printf("Second\n");
	else printf("First\n");
	return 0;
}