#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};
int m, n;
int ans = 0;
int board[91][91];

int dfs(int x,int y, int ans){
    rep(i, 4){
		int nowx = now.first + dx[i];
		int nowy = now.second + dy[i];
		if(0 <= nowx && nowx < m && 0 <= nowy && nowy < n && board[nowx][nowy] == 1){
			board[nowx][nowy] = 0;//使ったことを示すために0
			ans = max(ans, dfs(nowx, nowy, ans + 1));
			board

    return a;
}

int main(void){
	while(1){
		int m, n; scanf("%d %d", &m, &n);
		if(m == 0 && n == 0) return 0;
		int board[91][91];//どこに氷があるかを記憶
		rep(i, m) rep(j, n) scanf("%d", &board[i][j]);
		int memo[91][91];//回数をメモする
		rep(i, 91) rep(j, 91) memo[i][j] = 0;

		queue<pair<int, int> > q;
		int ans = 0;
		rep(x, m){
			rep(y, n){
				if(board[x][y] == 1) q.push(make_pair(x, y));//スタート時点を決める
				memo[x][y] = 1;
				while(!q.empty()){
					pair<int, int> now = q.front(); q.pop();
					// printf("x %d  y %d\n", x, y);
					// printf("now.fi %d  now.se %d\n", now.first, now.second);
					int dist = memo[now.first][now.second];
					rep(i, 4){
						int nowx = now.first + dx[i];
						int nowy = now.second + dy[i];
						if(0 <= nowx && nowx < m && 0 <= nowy && nowy < n && board[nowx][nowy] == 1){
							/*
							if(memo[nowx][nowy] == 0){
								memo[nowx][nowy] = dist + 1;
								q.push(make_pair(nowx, nowy));
							}
							*/
							if(memo[nowx][nowy] == 0) q.push(make_pair(nowx, nowy));
							if(dist + 1 > memo[nowx][nowy]) memo[nowx][nowy] = dist + 1;
						}
					}
				}
				rep(i, m)rep(j, n) ans = max(ans, memo[i][j]);//最大値の更新
				//初期化
				rep(i, 91) rep(j, 91) memo[i][j] = 0;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}