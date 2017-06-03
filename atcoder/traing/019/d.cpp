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

int N, M;
int A[100010], B[100010];
vector<int> G[100010];

int used[100010];
vector<int> ans;
void dfs(int u){
	used[u] = 1;
	ans.pb(u);
	for(auto v : G[u]){
		if(used[v]) continue;
		dfs(v);
		return;
	}
}

bool check(int u){
	for(auto v : G[u]){
		if(!used[v]) return false;
	}
	return true;
}



int main(void){
	cin >> N >> M;
	rep(i, M) cin >> A[i] >> B[i];
	rep(i, M) A[i]--, B[i]--;
	rep(i, M) G[A[i]].pb(B[i]), G[B[i]].pb(A[i]);

	vector<int> v;
	rep(i, N) v.pb(i);
	sort(all(v), [&](int a, int b){return G[a].size() < G[b].size();});

	for(auto start : v){
		ans.clear();
		rep(i, 100010) used[i] = 0;
		dfs(start);
		// if(!check(start)) continue;
		printf("%d\n", (int)ans.size());
		for(auto u : ans) printf("%d ", u + 1);
		printf("\n");
		return 0;
	}
	return 0;
}