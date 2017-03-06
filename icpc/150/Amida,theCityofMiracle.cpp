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

void slove(int n, int m, int a){
	int board[1000][100] = {{0}};//board[高さ][列]
	rep(i, m){
		int h, l, r;
		scanf("%d %d %d", &h, &l, &r);
		board[1000 - h][l] = 1;
		board[1000 - h][r] = 1;
	}

	pint now = mp(0, a);//now.fi　高さ now.se 列
	while(now.fi <= 999){
		//printf("nowfi%d  now.se%d\n", now.fi, now.se);
		if (board[now.fi][now.se - 1] == 1){
			board[now.fi][now.se] = 0;//何度も同じとこを往復しないように0で初期化
			now.se--;//左側につながる線がある
		} 
		else if(board[now.fi][now.se + 1] == 1){
			board[now.fi][now.se] = 0;//何度も同じとこを往復しないように0で初期化
			now.se++;//右側につながる線がある
		}
		else{
			now.fi++;//アミダくじをしたに下げる
		}
	}
	printf("%d\n", now.se);
	return;
}

int main(void){
	int n, m, a;
	rep(i, 1000){
		scanf("%d %d %d", &n, &m, &a);
		if(n == 0) break;
		slove(n, m, a);
	}	

	return 0;
}
