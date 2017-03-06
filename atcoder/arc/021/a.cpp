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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int board[5][5];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			scanf("%d", &board[i][j]);
		}
	}

	int nx, ny;
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				nx = j + dx[k];
				ny = i + dy[k];
				if (nx >= 0 && nx <= 3 && ny >= 0 && ny <= 3)
				{
					if (board[i][j] == board[ny][nx]){
						printf("CONTINUE\n");
						return 0;
					}
					
				}
			}
		}
	}

	printf("GAMEOVER\n");

	return 0;
}