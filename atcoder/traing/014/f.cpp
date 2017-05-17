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

int N, A, B;
int x[110], y[110], u[11], v[11];

int solve(vector<vector<int>> &g, vector<int> sink){
	// rep(i, N) printf("sink %d\n", sink[i]);
	queue<int> q;
	bool used[110];
	rep(i, 110) used[i] = 0;
	int ret = 0;
	rep(i, N){
		if(sink[i]) continue;
		q.push(i); //start
		used[i] = 1;
		// printf("first %d\n", i);
		ret++;
	}
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto v : g[u]){
			if(used[v]) continue;
			// printf("v %d sink %d\n", v, sink[v]);
			sink[v]--;
			if(sink[v]) continue;
			q.push(v);
			used[v] = 1;
			ret++;
		}
	}
	return ret;
}

int main(void){
	cin >> N >> A;
	rep(i, A) cin >> x[i] >> y[i];
	rep(i, A) x[i]--, y[i]--;
	cin >> B;
	rep(i, B) cin >> u[i] >> v[i];
	rep(i, B) u[i]--, v[i]--;

	int ans = 0;
	for (int mask = 0; mask < (1<<B); ++mask){
		vector<vector<int>> G(N);
		vector<int> SINK(N);
		rep(i, A){
			G[y[i]].pb(x[i]); SINK[x[i]]++;
		}
		rep(i, B){
			if(mask & (1<<i))G[u[i]].pb(v[i]), SINK[v[i]]++;
			else SINK[u[i]]++;
		}
		int tmp = solve(G, SINK);
		// printf("mask %d tmp %d\n", mask, tmp);
		chmax(ans, tmp);
	}
	printf("%d\n", ans);
	return 0;
}