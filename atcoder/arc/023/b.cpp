#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

int board_num[1010][1010];
int board[1010][1010];
int R, C, D;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

int main(void){
	scanf("%d %d %d", &R, &C, &D);
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}

	queue <pair<int, int> > Q;
	Q.push(make_pair(0, 0)); //(縦,横)
	for (int i = 0; i < D; ++i) //D回移動させる
	{
		int memo[1010][1010] = {0}; //どこの場所に行けてるかをメモっておく
		queue<pair<int, int> > Q_tmp;

		while(!Q.empty()){
			pair<int, int> tmp;
			tmp = Q.front();
			Q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int nx = tmp.second + dx[i];
				int ny = tmp.first + dy[i];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R)
					continue; //以下の処理をスキップ　以下の処理をスキップしてループの先頭に
				if(memo[ny][nx] == 1)
					continue; //すでにキューに入れているからこれ以上入れる必要はない
				memo[ny][nx] = 1; //まだキューに入れてない場所
				Q_tmp.push(make_pair(ny, nx)); //(縦,横)
			}
		}
		Q = Q_tmp; //スタックがなくなったことを確認できるように次回の情報は一度他のキューに入れて、それがなくなったことを確認後元のキューに代入
	}

	//D回動かした後の情報がスタックに入っているので、それを利用
	int ans = 0;
	while(!Q.empty()){
		pair<int, int> s;
		s = Q.front();
		Q.pop();
		if (board[s.second][s.first] > ans)
		{
			ans = board[s.second][s.first];
		}
	}

	printf("%d\n", ans);
	return 0;
}