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

int N, Q;
int p[100010];
string T[100010];
int NUM[100010];

vector<int> G[100010];
int ans[100010];
bool used[100010];


// WA

void dfs(int u, int k) {
	for(auto v : G[u]) {
		ans[v] = k;
		if(used[v]) continue;
		dfs(v, k);
	}
}

int main(void) {
	while(1){
		scanf("%d %d", &N, &Q);
		if(N == 0 && Q == 0) break;
		rep(i, N - 1) scanf("%d", &p[i]);
		rep(i, Q){
			cin >> T[i] >> NUM[i];
		}
		rep(i, Q) NUM[i]--;

		rep(i, 100010) G[i].clear();
		rep(i, 100010) ans[i] = 0;
		rep(i, 100010) used[i] = false;

		rep(i, N - 1) G[p[i] - 1].pb(i + 1);

		ll ret = 0;
		rep(i, Q) {
			if(T[i] == "Q") {
				// printf("ans %d\n", ans[NUM[i]] + 1);
				ret += ans[NUM[i]] + 1;
			}else{
				used[NUM[i]] = true;
				dfs(NUM[i], NUM[i]);
			}
		}
		printf("%lld\n", ret);
	}
	return 0;
}
