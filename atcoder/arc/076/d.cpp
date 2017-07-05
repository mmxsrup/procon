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

int N;
int x[100010], y[100010];
vector<tuple<int, int, int>> g;

int main(void) {
	cin >> N;
	rep(i, N) cin >> x[i] >> y[i];
	vector<tuple<int, int, int>> a(N), b(N);
	rep(i, N) a[i] = make_tuple(x[i], y[i], i), b[i] = make_tuple(y[i], x[i], i);
	sort(all(a)), sort(all(b));

	rep(i, N - 1){
		int u, v;
		u = get<2>(a[i]), v = get<2>(a[i + 1]);
		g.push_back(make_tuple(x[v] - x[u], u, v));
	}
	rep(i, N - 1){
		int u, v;
		u = get<2>(b[i]), v = get<2>(b[i + 1]);
		g.push_back(make_tuple(y[v] - y[u], u, v));
	}

	sort(all(g));
	DisjointSet uf(N + 10);
	ll ans = 0;

	for(auto t : g) {
		int cost, u, v;
		tie(cost, u, v) = t;
		if(!uf.same(u, v)) {
			uf.unite(u, v);
			ans += cost;
		}
	}
	printf("%lld\n", ans);
	return 0;
}