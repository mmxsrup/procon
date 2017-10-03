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

int N;
int a[100010], b[100010];
vector<int> G[100010];
int memo[100010];

int main(void) {
	cin >> N;
	rep(i, N - 1) cin >> a[i] >> b[i];
	rep(i, N - 1) a[i]--, b[i]--;
	rep(i, N - 1) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);

	queue<pair<int, int>> que;
	que.push(mp(0, 1)), que.push(mp(N - 1, 2));
	memo[0] = 1, memo[N - 1] = 2;
	while(!que.empty()) {
		auto tmp = que.front(); que.pop();
		int u = tmp.fi, num = tmp.se;
		// printf("u %d num %d\n", u, num);
		for(auto v : G[u]) {
			if(memo[v] != 0) continue;
			memo[v] = num;
			que.push(mp(v, num));
		}
	}
	int F = 0, S = 0;
	rep(i, N) {
		if(memo[i] == 1) F++;
		else if(memo[i] == 2) S++;
	}
	if(F > S) printf("Fennec\n");
	else printf("Snuke\n");
	return 0;
}