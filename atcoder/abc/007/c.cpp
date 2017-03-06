/*
幅優先探索　queue
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
#include <list>
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

int main(void){
	int r, c;
	scanf("%d %d", &r, &c);
	int sx, sy;
	int gx, gy;
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &gx, &gy);

	char borad_tmp[55][55];
	int board[55][55];
	reps(i, 1, r + 1){
		reps(j, 1, c + 1){
			scanf("%s", borad_tmp[i]);
		}
	}

	reps(i, 1, r + 1){
		reps(j, 1, c + 1){
			if (borad_tmp[i][j] == '.')
			{
				board[i][j] = 0; //道
			}else{
				board[i][j] = 1; //壁
			}
		}
	}

	reps(i, 1, r + 1){
		reps(j, 1, c + 1){
			printf("%d", board[i][j]);
		}
		printf("\n");
	}



	queue<pint> Q;
	Q.push(mp(sy, sx)); //Q(y, x) 
	int cnt[55][55];
	cnt[sy][sx] = 0;

	while(!Q.empty()){
		pint Q_tmp = Q.front();
		Q.pop();

		rep(i, 4){
			int nx = Q_tmp.se + dx[i];
			int ny = Q_tmp.fi + dy[i];
			if (1 <= nx && nx <= c && 1 <= ny && ny <= r && board[ny][nx] == 0)
			{
				cnt[ny][nx] = cnt[Q_tmp.fi][Q_tmp.se] + 1;
				Q.push(pint(nx, ny));
			}

			if (nx == gx && ny == gy){
				printf("%d\n", cnt[ny][nx]);
				return 0;
			}
		}
	}

	return 0;
}
































