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

int N, M, K, S; // 頂点 道の数 ゾンビに支配れている街の数 S本以上道路を使って到達できる町を危険
int P, Q; //安全 危険
int C[100010]; // ゾンビに支配れている
set<int> mC;
int A[200010], B[200010]; //A[i] <-> B[i]

vector<int> tG[100010];
bool kiken[100010];
int dist[100010]; //危険な町からの最短経路
void iskiken(void){
	rep(i, 100010) dist	[i] = INF;
	queue<pair<int, int> > q;
	rep(i, K){
		q.push(mp(0, C[i]));
		dist[C[i]] = 0;
	}
	while(!q.empty()){
		auto tmp = q.front(); q.pop();
		int u = tmp.se, d = tmp.fi; //現在の頂点, 距離
		if(d >= S) continue;
		for(auto v : tG[u]){
			if(dist[v] > d + 1){
				dist[v] = d + 1;
				q.push(mp(d + 1, v));
			}
		}
	}
	rep(i, N)if(dist[i] <= S) kiken[i] = true;
}


const int MAX_N = 200010;
vector<pair<int, ll> > G[MAX_N];
vector<ll> dijkstra(int start){
	vector<ll> dist(MAX_N, INFF);
	dist[start] = 0;//dist[i] :=　start->iまでの最短距離
	priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > >  que;
	que.push(make_pair(0, start));
	while(!que.empty()){
		ll cost; int u;//今までにかかった時間 現在の頂点
		cost = que.top().first, u = que.top().second;
		que.pop();
		if(dist[u] < cost) continue;
		for (auto tmp : G[u]){
			int v = tmp.first; ll time = tmp.second;//隣接する頂点 その頂点まで行く時間
			if(dist[v] > dist[u] + time){//u->v
				dist[v] = dist[u] + time;
				que.push(make_pair(dist[v], v));
			}
		}
	}
	return dist;
}

int main(void){
	cin >> N >> M >> K >> S;
	cin >> P >> Q;
	rep(i, K) cin >> C[i], C[i]--;
	rep(i, K) mC.insert(C[i]);
	rep(i, M) cin >> A[i] >> B[i];
	rep(i, M) A[i]--, B[i]--;
	rep(i, M) tG[A[i]].pb(B[i]), tG[B[i]].pb(A[i]);
	iskiken();

	rep(i, M){
		if(mC.count(A[i]) != 0 || mC.count(B[i]) != 0) continue;
		if(A[i] == N - 1) G[B[i]].pb(mp(A[i], 0));
		else if(B[i] == N - 1) G[A[i]].pb(mp(B[i], 0));
		else{
			G[A[i]].pb(mp(B[i], kiken[B[i]] ? Q : P));
			G[B[i]].pb(mp(A[i], kiken[A[i]] ? Q : P));
		}
	}
	auto ret = dijkstra(0);
	printf("%lld\n", ret[N - 1]);
	return 0;
}