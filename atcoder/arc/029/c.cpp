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
int c[100010], a[200010], b[200010], r[200010];

bool f[100010];

int main(void) {
	cin >> N >> M;
	rep(i, N) cin >> c[i];
	rep(i, M) cin >> a[i] >> b[i] >> r[i];

	vector<pair<int, int>> v;
	rep(i, N) v.pb(mp(c[i], i));
	map<pair<int, int>, int> ma;
	rep(i, M) G[a[i]].pb(mp(b[i], r[i])), G[b[i]].pb(mp(a[i], r[i]));

	rep(i, v.size()) {
		if(f[i]) continue;
		queue<int> que;
		que.push(i);
		while(!que.empty()) {
			auto u = que.front(); que.pop();
			for(auto tm : G[u]) {
				int v = tm.fi, cost = tm.se;
				if(cost < c[v]) { // 辺を張った方が安い
					
				}
			}
		}
	}
	return 0;
}