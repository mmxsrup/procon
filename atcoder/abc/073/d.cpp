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

const int MAX_N = 1010;
using TYPE = ll; // 距離の型を入れる
vector<pair<int, TYPE> > G[MAX_N];
vector<TYPE> dijkstra(int start){
	vector<TYPE> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<TYPE, int>, vector<pair<TYPE, int> >, greater<pair<TYPE, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		TYPE cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; TYPE time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

ll memo[1100][1100];
ll N, M, R;
ll r[100];
ll A[100010], B[100010];
ll C[100010];

int main() {
	cin >> N >> M >> R;
	rep(i, R) cin >> r[i];
	rep(i, R) r[i]--;
	rep(i, M) cin >> A[i] >> B[i] >> C[i];
	rep(i, M) A[i]--, B[i]--;
	rep(i, M) G[A[i]].pb(mp(B[i], (ll)C[i])), G[B[i]].pb(mp(A[i], (ll)C[i]));

	rep(i, R)rep(j, R) {
		auto d = dijkstra(r[i]);
		memo[r[i]][r[j]] = d[r[j]];
	}
	/*
	rep(i, R){
		rep(j, R) printf("%d ", memo[r[i]][r[j]]);
		printf("\n");
	}
	*/
	ll ans = INFF;
	vector<ll> v;
	rep(i, R) v.pb(r[i]);
	do {
		// for(auto k : v) printf("%d ", k);
		// printf("\n");
		ll tmp = 0;
		rep(i, R - 1) {
			tmp += memo[v[i]][v[i + 1]];
		}
		// printf("%lld\n", tmp);
		chmin(ans, tmp);
	}while( next_permutation(v.begin(), v.end()) );
	printf("%lld\n", ans);
	return 0;
}