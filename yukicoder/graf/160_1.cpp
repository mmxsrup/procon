#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pairt
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int dist[210][210];
const int INF = 1e9;

//ワーシャルフロイド法 全点対間最短経路をもとめるとき) (0オリジン)
//dpを利用している
//dist[i][i] = 0 dist[i][j](経路がないもの)= dist[j][i] = INF(1e9)で初期化しておくこと
//dist[i][j] = dist[j][i] = (距離)を代入しておくこと
//この関数を利用することで、dist[i][j]の値(i,j間の距離)の最小値に更新されていく
void floyd (int n){//nは頂点の数
	rep(k, n) rep(i, n) rep(j, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	fukugen();
	return;
}

void fukugen(void){
	int len = dist[s][g];
	printf("%d ", s);
	while(k != g){
		if(dist[s][k] + dist[k][g] == len)
	}
	return;
}

int main(void){
	int n, m, s, g;
	cin >> n >> m >> s >> g;
	//大きめの数字で初期化
	rep(i, 210)rep(j, 210) dist[i][j] = dist[j][i] = INF;
	//同じ時点は0
	rep(i, 210) dist[i][i] = 0;
	//入力
	rep(i, m){
		int a, b, c;
		scanf("%d%d%d", &a,&b,&c);
		//a--; b--; //0オリジンへ
		dist[a][b] = dist[b][a] = c;//バスは往復可能なので、2つに代入すること
	}

	floyd(n);


	return 0;		
}