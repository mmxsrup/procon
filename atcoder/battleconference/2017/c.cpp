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

int n, m;
int a[61010], b[61010];
vector<int> G[310];
int memo[310][310]; // memo[s][t] := s-> * -> tの数

void dfs(int s, int t, int cur, int cnt){ 
	// printf("%d %d %d %d\n", s, t, cur, cnt);
	if(cnt == 2 && cur == t) memo[s][t]++;
	if(cnt == 2) return;
	for(auto x : G[cur]){
		dfs(s, t, x, cnt + 1);
	}
}

int main(void){
	cin >> n >> m;
	rep(i, m){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	rep(i, m){
		G[a[i]].pb(b[i]);
	}
	rep(i, n)rep(j, n){
		dfs(i, j, i, 0);
	}
	int ret = 0;
	rep(i, n)rep(j, n){
		ret += memo[i][j] * memo[i][j];
	}
	printf("%d\n", ret);
	return 0;
}