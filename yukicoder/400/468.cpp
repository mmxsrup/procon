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

int n, m;
vector<pair<int, int> > dist[100010];
int cost[100010];
bool used[100010], check[100010];

void max_dfs(int u){//赤色の数字を求める
	if(used[u]) return;
    if(!used[u]){
    	used[u] = true;
  		for(auto v : dist[u]){ // u -> v
  			max_dfs(v.fi);
  			//ゴールから戻す
  			chmax(cost[u], cost[v.fi] + v.se);
  		}
    }
}

void kuriteical_dfs(int u){//赤色の線
    if(check[u]) return;
    if(!check[u]){
    	check[u] = true;
  		for(auto v : dist[u]){ // u -> v
  			if(cost[u] == cost[v.fi] + v.se){//ぎりぎり
  				kuriteical_dfs(v.fi);
  			}
  		}
    }
}
int main(void){
	cin >> n >> m;
	rep(i, m){
		int a, b, c; cin >> a >> b >> c;
		dist[a].pb(mp(b, c));//a -> b
	}
	max_dfs(0);
	kuriteical_dfs(0);
	int ans = n;
	rep(i, n){
		if(check[i]) ans--;
	}
	printf("%d %d/%d\n", cost[0], ans, n);
	return 0;
}