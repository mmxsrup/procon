//最大増加列を求めればいい。
/*dpを使う。dpを使うなら漸化式を立てる必要がある。
i=0　または　dp[i-1]<a(j)なら　dp[i] = min(dp[i], a(j))
である。これを実装すればいい O(n^2)

この回答だとTLE 
if(dp[j - 1] < c[i])　dp[j] = min(dp[j], c[i]);
ここでdp[j - 1] < c[i]を満たすの中で、j - 1が最大のものを全探索で探している部分が無駄、dpは単調増加（ソートされた状態になっている）
から2分探索すれば(nlogn)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <bitset>
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

int INF = 1000000000;
int dp[30010];//dp[j]j個の増加列を作った時のj番目の数字（最後尾）の数字の中で最大のものを入れていくと良い
int c[30010];

int  LIS(int n){
	int ans = 1;
	rep(i, n){//何番目の数字を見ているか
		rep(j, n){//dpを見ていく
			//今見ているc[i]より大きな数字が入っていれば、dpを更新できるかも
			if(j == 0) dp[0] = min(dp[0], c[0]);//dp[0]により大きなものを入れていく
			else if(dp[j - 1] < c[i]){
				dp[j] = min(dp[j], c[i]);//部分列の最後尾となり得る、c[i]がdp[j]に入っている数字より大きければ更新
				ans = max(ans, j + 1);//dp[j]が大きな数字に更新されたらj + 1個の増加列が作れたということ
			}
		}
	}
	return ans;
}

int main(void){
	//入力
	int n; scanf("%d", &n);
	rep(i, n) scanf("%d", &c[i]);
	//初期化
	rep(i, n) dp[i] = INF;

	printf("%d\n", n - LIS(n));
	return 0;
}