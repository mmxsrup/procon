//動的計画法かと思ったけど違う

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
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int INF = 100000000;
int dp[100002][100002][100001];//dp[aのmax][bのmax][何番目のサンプルか] = 最大値
int num[100001][2];//ab[番号][0]:a ab[番号][1]:b

int main(void){
	int n; scanf("%d", &n);
	rep(i, n) scanf("%d %d", num[i][0], num[i][1]);

	dp[1][100002] = 0;
	rep(i, n){
		//この番号を撮るとき
		
	}
	return 0;	
}