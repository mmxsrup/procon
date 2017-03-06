#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, c, v;
int s[1510], t[1510], y[1510], m[1510];

vector<tuple<int, int, int> > G[110];
//dist[u][money] :=　現在の頂点がuで残りのお金がmoneyのときの最短時間
int dist[52][310];

void dijkstra(int start){
    rep(i, 52)rep(j, 310) dist[i][j] = INF; 
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > >  que;
    que.push(make_tuple(0, start, c));//時間　現在の頂点　残りの金
    dist[0][c] = 0;
    while(!que.empty()){
        int time, u, money;//今までにかかった時間 現在の頂点　残りの金
        tie(time, u, money) = que.top(); que.pop();
        if(dist[u][money] < time) continue;
		        
        for (auto tmp : G[u]){
            int v, now_money, now_time;//v u->vの金 u->vの時間
            tie(v, now_money, now_time) = tmp;
            if(money - now_money < 0) continue;
            if(dist[v][money - now_money] > dist[u][money] + now_time){
	            dist[v][money - now_money] = dist[u][money] + now_time;
	            que.push(make_tuple(dist[v][money - now_money], v, money - now_money));
	        }
        }   
    }   
}

int main(void){
	scanf("%d %d %d", &n, &c, &v);
	rep(i, v) scanf("%d", &s[i]), s[i]--;
	rep(i, v) scanf("%d", &t[i]), t[i]--;
	rep(i, v) scanf("%d", &y[i]);
	rep(i, v) scanf("%d", &m[i]);
	rep(i, v){
		G[s[i]].pb(make_tuple(t[i], y[i], m[i]));//s->t y:=お金 m:= 時間
	}
	dijkstra(0);
	int ans = INF;
	rep(i, 310) chmin(ans, dist[n - 1][i]);
	if(ans == INF)printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}