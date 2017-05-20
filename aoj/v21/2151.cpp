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

using tup = tuple<ll, int, int>;
vector<tuple<int, int, int>> G[110]; // G[i] := i->j dist enemy
//dist[i][j] := 頂点0から頂点iへ 残り予算Lでつくときの敵の合計の最小値
int dist[110][110];

int N, M, L;

void dijkstra(int start){
	rep(i, 110)rep(j, 110) dist[i][j] = INF;
    priority_queue<tup, vector<tup>, greater<tup>> que; // コスト 位置 予算
    dist[start][L] = 0;
    que.push(make_tuple(0, start, L));
    while(!que.empty()){
        int cost, u, money;
        tie(cost, u, money) = que.top(); que.pop();
        // printf("cost %d u %d moeny %d\n", cost, u, money);
        // if(dist[u][money] < cost) continue;
        if(u == N - 1) break;
        for(auto tm : G[u]){
            int v, len, enemy;
            tie(v, len, enemy) = tm;
            // printf("v %d len %d enemy %d\n", v, len, enemy);
            if(len > money){
            	if(cost + enemy < dist[v][money]){
            		dist[v][money] = cost + enemy;
            		que.push(make_tuple(dist[v][money], v, money));
            	}
            }else{ //守れる
            	if(cost < dist[v][money - len]){
            		// printf("k\n");
            		dist[v][money - len] = cost;
            		que.push(make_tuple(dist[v][money - len], v, money - len));
            	}
            	if(cost + enemy < dist[v][money]){
            		dist[v][money] = cost + enemy;
            		que.push(make_tuple(dist[v][money], v, money));
            	}
            }
        }
    }
}

int main(void){
	while(1){
		scanf("%d %d %d", &N, &M, &L);
		if(N == 0) return 0;
		rep(i, 110) G[i].clear();

		rep(i, M){
			int a, b, d, e; scanf("%d %d %d %d", &a, &b, &d, &e);
			a--, b--;
			G[a].pb(make_tuple(b, d, e)), G[b].pb(make_tuple(a, d, e));
		}
		// printf("dis\n");
		dijkstra(0);
		int ans = INF;
		rep(i, L + 1) chmin(ans, dist[N - 1][i]);
		printf("%d\n", ans);
	}
	return 0;
}