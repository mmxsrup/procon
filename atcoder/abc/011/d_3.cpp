//単純な再帰関数を用いた深さ優先探索
//さらにメモすることによりメモ化再帰
//部分点100点狙い
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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
double goalx, goaly;
double n;
double sum = 0;
int dp[50][100][100] = {-1};

void dfs(int cnt, double x, double y){
	if(dp[cnt][x][y] != -1) return dp[cnt][x][y];
	if(cnt == n){
		if(x == goalx && y == goaly) sum++;
		return;
	}else{
		cnt++;
		//再帰関数
		rep(i, 4)dfs(cnt, x + dx[i], y + dy[i]);
	}
}
int main(void){
	rep(i, )
	double d;
	cin >> n >> d;
	double x, y;
	cin >> x >> y;
	//圧縮して、一度の動ける距離を１に
	goalx = x / d;
	goaly = y / d;
	dfs(0, 0.0, 0.0);
	//printf("%f\n", sum);
	double bunbo = pow(4.0, n);
	printf("%.13f\n", sum / bunbo);
	return 0;
}