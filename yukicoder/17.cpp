#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

const int MAX_N = 51, INF = 1e8;
int s[MAX_N];
int dist[MAX_N][MAX_N];

//dist[i][i] = 0 dist[i][j](経路がないもの)= dist[j][i] = INF(1e9)で初期化しておくこと
void floyd (int n){//nは頂点の数
	rep(k, n) rep(i, n) rep(j, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main(void){
	rep(i, MAX_N)rep(j, MAX_N) dist[i][j] = dist[j][i] = INF;
	rep(i, MAX_N) dist[i][i] = 0;

	int n; cin >> n;
	rep(i, n) cin >> s[i];
	int m; cin >> m;
	rep(i, m){
		int a, b, c; cin >> a >> b >> c;
		dist[a][b] = dist[b][a] = c;
	}
	floyd(n);
	int ans = INF, tmp;
	for (int i = 1; i < n - 1; ++i){
		for (int j = 1; j < n - 1; ++j){
			if(i != j){
				//移動コストと滞在コストの合計
				tmp = dist[0][i] + dist[i][j] + dist[j][n - 1] + s[i] + s[j];
				ans = min(ans, tmp);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
