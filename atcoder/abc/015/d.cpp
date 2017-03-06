/*
dp臭
ナップサック問題に商品の個数の制約を追加した問題
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

int dp[10001][51][51]//dp[幅の合計値][使用した枚数][何番目まで調べたか] = 重要度の最大値
int main(void){
	int w; cin >> w;//幅のサイズ
	int n, k;
	vpint v(n); //fi 幅　se　重要度
	rep(i, n){
		int a, b; scanf("%d %d", &a, &b);
		v[i].fi = a; v[i].se = b;
	}
	rep
	dp[0][0][0] = 0;
	// dp[ i 枚考慮 ][ 幅が j ][ 使った数が k ] := max( 重要度 )
	rep(i, n){
		rep(j, w + 1){
			rep(k, K + 1){
				if(i >= )
			}
		} 
	}

}