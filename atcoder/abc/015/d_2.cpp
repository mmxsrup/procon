/*
dp臭
ナップサック問題に商品の個数の制約を追加した問題
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
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

int main(void){
	int W, n, K;
	cin >> W >> n >> K;
	vector<int> a(n), b(n);
	rep(i, n) scanf("%d %d", &a[i], &b[i]);

	//dp[今見ているスクショが何枚目か][今まで選んだスクショの枚数][今まで選んだスクショの合計幅] = 価格の最大値
	vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(K + 1, vector<int>(W + 1))); // vc[n][K][10000 * K]と同じ

	//初期化
	rep(i, n + 1) rep(j, K + 1)rep(k, W + 1) dp[i][j][k] = -1;

	dp[0][0][0] = 0;
	int ans = 0;//答えを格納
	rep(i, n){//iは今見ているスクショが何枚目か
		rep(k, K){//kは今まで選んだスクショの枚数
			rep(w, W + 1){//wは今まで選んだスクショ幅の合計値
				if(dp[i][k][w] < 0) continue;//今見ている状況が存在しないとき
				//i枚目のスクショを選ばないとき
				dp[i + 1][k][w] = max(dp[i + 1][k][w], dp[i][k][w]);
				//i番目のスクショを選ぶとき
				if(w + a[i] <= W){//合計幅が上限を超えないかチェック
					dp[i + 1][k + 1][w + a[i]] = max(dp[i + 1][k + 1][w + a[i]], dp[i][k][w] + b[i]);
					ans = max(ans, dp[i + 1][k + 1][w + a[i]]);//値が更新されていったら、値を更新していく
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}