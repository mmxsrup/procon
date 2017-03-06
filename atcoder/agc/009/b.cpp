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

int n;
int a[100010];
vector<int> G[100010];
// int used[100010];
int cnt[100010];

int dfs(int u, int p){
	if(G[u].size() == 0) return 1;
	int ret = 0;
	for(auto v : G[u]){
		ret += dfs(v, u);
	}
	cnt[u] = ret + 1;
	// printf("%d %d\n", u, cnt[u]);
	return cnt[u];
}

int main(void){
	cin >> n;
	reps(i, 2, n + 1){
		scanf("%d", &a[i]);
	}

	reps(i, 2, n + 1){
		G[a[i]].pb(i);
	}
	/*
	queue<pair<int, int> > que;
	que.push(mp(1, 0));
	int ans = 0;
	while(!que.empty()){
		auto u = que.front(); que.pop();
		printf("%d %d\n", u.fi, u.se);
		for(auto v : G[u.fi]){
			if(used[v] == 0){
				que.push(mp(v, u.se + 1));
				chmax(ans, u.se + 1);
				used[v] = 1;
			}
		}
	}
	printf("%d\n", ans);
	*/
	dfs(1, -1);
	int ans = 0;
	reps(i, 2, n + 1){
		if(a[i] == 1){
			chmax(ans, cnt[i]);
		}
	}
	// chmax(ans, cnt[1]);
	printf("%d\n", ans);
	return 0;
}