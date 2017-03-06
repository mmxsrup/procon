/*
ダイクストラ法 　単一始点最短経路を求めるアルゴリズム
	ある頂点を始点とした時、それ以外の頂点への最短経路を求める
ワーシャルフロイド法　全点対間最短経路を求めるアルゴリズム
	任意の頂点から任意の頂点までの最短経路を求める
*/
#include <iostream>
#include <algorithm>
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
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int dist[310][310];
const int INF = 1e9;

//ワーシャルフロイド法 全点対間最短経路をもとめるとき) (0オリジン)
//dpを利用している
//dist[i][i] = 0 dist[i][j](経路がないもの)= dist[j][i] = INF(1e9)で初期化しておくこと
//dist[i][j] = dist[j][i] = (距離)を代入しておくこと
//この関数を利用することで、dist[i][j]の値(i,j間の距離)の最小値に更新されていく
void floyd (int n){//nは頂点の数
	rep(k, n) rep(i, n) rep(j, n)
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
 
int main(void){
	int n, m;
	cin >> n>> m;
	//大きめの数字で初期化
	rep(i, 310)rep(j, 310) dist[i][j] = dist[j][i] = INF;
	//同じバス停は0
	rep(i, 310) dist[i][i] = 0;
	//入力
	rep(i, m){
		int a, b, t;
		scanf("%d%d%d", &a,&b,&t);
		a--; b--; //0オリジンへ
		dist[a][b] = dist[b][a] = t;//バスは往復可能なので、2つに代入すること
	}

	floyd(n);
	
	int ans = INF;
	rep(i, n){
		int x = 0;
		rep(j, n){
			//iのバス停と全てのバス停との間を移動する時にかかる時間の最大を探す
			x = max(x, dist[i][j]);
		}
		//かかる時間が最小になるところが答え
		ans = min(x, ans);
	}
	printf("%d\n", ans);
	return 0;		
}