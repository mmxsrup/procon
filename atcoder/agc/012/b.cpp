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

int N, M, Q;
int a[100010], b[100010];
int v[100010], d[100010], c[100010];
vector<int> G[100010];

bool used[100010];
int memo[100010];
void bfs(int start, int dist, int color){
	rep(i, 100010) used[i] = false;
	queue<pair<int, int>> q;
	q.push(mp(start, 0));
	used[start] = true, memo[start] = color;
	while(!q.empty()){
		auto tmp = q.front(); q.pop();
		int u = tmp.fi, d =tmp.se;
		if(d == dist) continue;
		for(int v : G[u]){
			if(used[v]) continue;
			// printf("u v %d %d\n", u, v);
			used[v] = true;
			memo[v] = color;
			q.push(mp(v, d + 1));
		}
	}
}

int main(void){
	cin >> N >> M;
	rep(i, M) cin >> a[i] >> b[i];
	rep(i, M) a[i]--, b[i]--;
	rep(i, M) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);
	cin >> Q;
	rep(i, Q) cin >> v[i] >> d[i] >> c[i];
	rep(i, Q){
		bfs(v[i] - 1, d[i], c[i]);
		// rep(i, N) printf("%d\n", memo[i]);
	}	

	rep(i, N) printf("%d\n", memo[i]);
	return 0;
}