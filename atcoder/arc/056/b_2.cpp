#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX_N = 200010;
int n, m; //町の数 道路の本数
int s;
vector<int> g[MAX_N];//グラフを表す隣接リスト
int d[MAX_N]; //d[i] := sからiに至るまでに通る道の中で、頂点番号の最小を一番大きくした時の頂点番号
typedef pair<int, int> P;//firstは最短距離,secondは頂点の番号

//今回はコストの大きい頂点から決めていく
void dijkstra(void){
    priority_queue<P> que;//firstが大きい順に
    rep(i, n) d[i] = -1;//初期化
    d[s] = s;
    que.push(make_pair(s, s));//fi: 巡ってきた最大頂点番号 se:今の頂点番号
  
    while(!que.empty()){
        auto p = que.top(); que.pop();
        int v = p.second;
        for(auto u : g[v]){//u:隣接している頂点の番号
        	int t = min(d[v], u);
            if(d[u] < t){//が更新されるとき
                d[u] = t;
                que.push(make_pair(d[u], u));
            }
        }
    }
}

int main(void){
	cin >> n >> m >> s;
	s--;
	rep(i, m){
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dijkstra();
	rep(i, n){
		if(d[i] >= i) cout << i + 1 << endl;
	}
	return 0;
}