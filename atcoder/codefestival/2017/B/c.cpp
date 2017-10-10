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
int a[100010], b[100010];
vector<int> G[100010];
unordered_set <int> st[100010];

bool f;
ll ans = 0;

int main(void) {
	cin >> n >> m;
	rep(i, m) scanf("%d %d", &a[i], &b[i]);
	rep(i, m) a[i]--, b[i]--;

	rep(i, m) G[a[i]].pb(b[i]), G[b[i]].pb(a[i]);
	rep(i, m) st[min(a[i], b[i])].insert(max(a[i], b[i]));


	set<pair<int, int>> se;
	rep(i, 1) {
		rep(i, n){
			for(auto t : st[i]) {
				for(auto u : G[i]) for(auto v : G[t]) {
					if(u == v) continue;
					if(st[min(u, v)].count(max(u, v)));
					se.insert(mp(min(u, v), max(u, v)));
				}
			}
		}
	}


	set<pair<int>> re;
	for(auto u : se)for(auto v : se) {
		if(u == v) continue;
		for(auto d1 : u)for()
	}


	ll size = 0;
	rep(i, n) size += add[i].size();
	ans = size - (ll)m;
	printf("%lld\n", ans);
	return 0;
}