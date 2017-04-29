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

// vector<pair<int, int>> G[100010];
const int MAX_N = 100010;
vector<pair<int, int> > G[MAX_N];
vector<int> dijkstra(int start, int goal){//スタートとゴールを逆に
	vector<long long> dist(MAX_N, INF);
	vector<int> pre(MAX_N, -1);//pre[i] := iの前の頂点
    dist[start] = 0;//dist[i] :=　start->iまでの最短距離
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    que.push(make_pair(0, start));
    while(!que.empty()){
        int cost, u, t;//今までにかかった時間 現在の頂点
        cost = que.top().first, u = que.top().second;
        que.pop();
        if(dist[u] < cost) continue;
        for (auto tmp : G[u]){
            int v = tmp.first, time = tmp.second;//隣接する頂点 その頂点まで行く時間
            if(dist[v] > dist[u] + time){//u->v
            	dist[v] = dist[u] + time;
            	pre[v] = u;
            	que.push(make_pair(dist[v], v));
            }else if(dist[v] == dist[u] + time){//辞書順最小
            	pre[v] = min(pre[v], u);
            }
        }
    }
    //経路復元
    vector<int> path;
    int s = start, t = goal;
	for (; t != s; t = pre[t]) path.push_back(t);
	path.push_back(s);
	return path; //start-> * -> goal startからgoalまでの最短経路(辞書順最小)
}

vector<pair<int, int> > rG[MAX_N];
vector<int> rdijkstra(int start, int goal){//スタートとゴールを逆に
	vector<long long> dist(MAX_N, INF);
	vector<int> pre(MAX_N, -1);//pre[i] := iの前の頂点
    dist[start] = 0;//dist[i] :=　start->iまでの最短距離
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > que;
    que.push(make_pair(0, start));
    while(!que.empty()){
        int cost, u, t;//今までにかかった時間 現在の頂点
        cost = que.top().first, u = que.top().second;
        que.pop();
        if(dist[u] < cost) continue;
        for (auto tmp : rG[u]){
            int v = tmp.first, time = tmp.second;//隣接する頂点 その頂点まで行く時間
            if(dist[v] > dist[u] + time){//u->v
            	dist[v] = dist[u] + time;
            	pre[v] = u;
            	que.push(make_pair(dist[v], v));
            }else if(dist[v] == dist[u] + time){//辞書順最小
            	pre[v] = min(pre[v], u);
            }
        }
    }
    //経路復元
    vector<int> path;
    int s = start, t = goal;
	for (; t != s; t = pre[t]) path.push_back(t);
	path.push_back(s);
	return path; //start-> * -> goal startからgoalまでの最短経路(辞書順最小)
}

vector<int> ans, anss;

void dfs(int now, int pre, int start){
	printf("%d %d %d\n", now, pre, start);
	for(auto u : G[now]){
		if(u.fi == pre) continue;
		if(u.fi == start){
			anss = ans;
			return;
		}
		ans.pb(u.fi);
		dfs(u.fi, now, start);
		ans.pop_back();
	}
	return;
}

int main(void){
	cin >> N >> M;
	rep(i, M) cin >> A[i] >> B[i];
	rep(i, M) A[i]--, B[i]--;
	rep(i, M){
		G[A[i]].pb(mp(B[i], 1)); G[B[i]].pb(mp(A[i], 1));
	}
	vector<int> memo1, memo2, memo3;
	rep(i, N){
		// printf("%d %d\n", i, G[i].size());
		if(G[i].size() == 1) memo1.pb(i);
		else if(G[i].size() == 2)memo2.pb(i);
		else if(G[i].size() == 3) memo3.pb(i);
	}
	vector<int> ret;
	
	if(memo1.size() >= 2){
		ret = dijkstra(memo1[0], memo1[1]);
		printf("%d\n", (int)ret.size());
		for(auto u : ret){
			printf("%d ", u + 1);
		}
		printf("\n");
		return 0;
	}else if(memo2.size() >= 2){
		int k1, k2;
		bool flag = false;
		rep(i, memo2.size() - 1){
			reps(j, i + 1, memo2.size()){
				auto f = find(all(G[memo2[i]]), mp(memo2[j], 1));
				if(f != G[memo2[i]].end()){
					k1 = i, k2 = j;
					flag = true;
					break;
				}

			}
			if(flag)break;
		}
		if(flag){

			rep(i, M){
				if(A[i] == memo2[k1] && B[i] == memo2[k2]) continue;
				if(A[i] == memo2[k2] && B[i] == memo2[k1]) continue;
				rG[A[i]].pb(mp(B[i], 1)); rG[B[i]].pb(mp(A[i], 1));
			}
			ret = rdijkstra(memo2[k1], memo2[k2]);
			printf("%d\n", (int)ret.size());
			for(auto u : ret){
				printf("%d ", u + 1);
			}
			printf("\n");
			return 0;
		}
	}
	

	// printf("k\n");
	if(memo3.size() >= 2){
		int d1 = G[memo3[0]][0].fi, d2 = G[memo3[0]][1].fi;
		int d3 = G[memo3[1]][0].fi, d4 = G[memo3[1]][1].fi;
		ret = dijkstra(d1, d4);
		if(ret[1] == d2 && ret[ret.size() - 2] == d3){
			printf("%d\n", (int)ret.size());
			printf("%d ", memo3[0]);
			for(auto u : ret){
				printf("%d ", u + 1);
			}
			printf("%d ", memo3[1]);
			printf("\n");
		}else if(ret[1] != d2 && ret[ret.size() - 2] != d3){
			printf("%d\n", (int)ret.size());
			printf("%d ", memo3[0]);
			printf("%d ", d2);
			for(auto u : ret){
				printf("%d ", u + 1);
			}
			printf("%d ", d3);
			printf("%d ", memo3[1]);
			printf("\n");
		}else if(ret[1] != d2){
			printf("%d\n", (int)ret.size());
			printf("%d ", memo3[0]);
			printf("%d ", d2);

			for(auto u : ret){
				printf("%d ", u + 1);
			}
			printf("%d ", memo3[1]);
			printf("\n");
		}

	}else{
		int k = 0;
		rep(i, 1000000000)k++;
	}
	return 0;
}