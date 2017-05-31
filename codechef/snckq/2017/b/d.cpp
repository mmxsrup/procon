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

class DisjointSet{
public:
	vector<int> rank, p;//rank:木の高さ p:親の頂点番号
	DisjointSet(){}
	DisjointSet(int size){//頂点の数
		rank.resize(size, 0);
		p.resize(size, 0);
		rep(i, size) makeSet(i);
	}
	bool same(int x, int y){ //同じ木にあるか
		return findSet(x) == findSet(y);
	}
	void unite(int x, int y){ // 木どうしをくっつける
		link(findSet(x), findSet(y));
	}
private:
	void makeSet(int x){
		p[x] = x;
		rank[x] = 0;
	}
	int findSet(int x){ //親を探す（ルートまで）
		if(x != p[x]){
			p[x] = findSet(p[x]);
		}
		return p[x];
	}
	void link(int x, int y){ //木の高さを考慮して木どうしをくっつける
		if(rank[x] > rank[y]){
			p[y] = x;
		}else{
			p[x] = y;
			if(rank[x] == rank[y]) rank[y]++;
		}
	}
};


int n, m;
int u[200010], v[200010];
vector<int> G[100010];
vector<int> d[100010];
void solve() {
	scanf("%d %d", &n, &m);
	rep(i, m)scanf("%d %d", &u[i], &v[i]);
	rep(i, m) u[i]--, v[i]--;
	rep(i, m) G[u[i]].pb(v[i]), G[v[i]].pb(u[i]);
	rep(i, m) d[min(G[u[i]].size(), G[v[i]].size())].pb(i);
	// rep(i, n) d[G[i].size()].pb(i);
	int cnt = n - 1;
	DisjointSet uf(n);
	vector<int> ans;

	/*
	rep(i, n){
		printf("i %d\n", i);
		for(auto k : d[i]) printf("%d ", k);
		printf("\n");
	}
	*/
	for (int i = n - 1; i >= 0; --i) {
		for(auto k : d[i + 1]){
			int s = u[k], t = v[k];
			// printf("s->t %d %d\n", s, t);
			// s->t
			if(!uf.same(s, t)){
				cnt--;
				uf.unite(s, t);
			}
		}
		ans.pb(cnt);
	}
	reverse(all(ans));
	rep(i, ans.size() - 1) printf("%d ", ans[i]);
	printf("%d\n", ans[n - 1]);
	return;
}

int main(void){
	int T; scanf("%d", &T);
	while(T--){
		solve();
	}
}