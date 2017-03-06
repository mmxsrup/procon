#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int n; 
int x[1010], y[1010], t[1010], r[1010];

int dist[5010]; //0->iへの最小コスト
bool used[5010]; //使った町を記録

void dijkstra(int start){
    rep(i, n) dist[i] = INF;//初期化
    dist[start] = 0;
    while(1){
        int v = -1;
        //まだ使われていない頂点のうち距離が最小のものを探す
        for (int u = 0; u < n; ++u){
            if(!used[u] && (v == -1 || dist[u] < dist[v])) v = u;
        }
        //最終的に距離が最小の町の番号がvに
        if(v == -1) break;
        used[v] = true;//使用した
        for (int u = 0; u < n; ++u){
            dist[u] = min(dist[u], dist[v] + G[v][u]);//この時に隣接リストのGだとできない
        }
    }
}

int main(void){
	cin >> n;
	rep(i, n){
		cin >> x[i] >> y[i] >> t[i] >> r[i];
	}
	dijkstra(0);

}