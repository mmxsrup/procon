/*
幅優先探索
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
using namespace std;

typedef long long ll;

int board[510][510];

int main(void){
	int H, W;
	char c;
	scanf("%d %d", &H, &W);

	for (int i = 0; i <= H; ++i)
	{
		for (int j = 0; j <= W; ++j)
		{
			scanf("%c", &c);
			if (c == '#')
			{
				board[i][j] = 0;
			}else if(c == '.'){
				board[i][j] = 1;
			}else if(c == 's'){
				board[i][j] = 2;
			}else{
				board[i][j] = 3;
			}
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (board[i][j] == 0)
			{
				printf("#");
			}else if(board[i][j] == 1){
				printf(".");
			}else if(board[i][j] == 2){
				printf("s");
			}else{
				printf("g");
			}
		}
		printf("\n");
	}

	return 0;
}