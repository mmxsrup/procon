/*
入力の練習
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;


char board[10][10]; //ボードの配列を作成
int kimatteru_x[5]; //決まっているQの位置を保存しておく
int kimatteru_y[5]; //決まっているQの位置を保存しておく

int main(void){
	int cnt = 0;
	//入力
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			scanf("%c", &board[i][j]);
			if (board[i][j] == 'Q')
			{
				kimatteru_x[cnt] = j;
				kimatteru_y[cnt] = i;
				cnt++;
			}
		}
		/*これを入れればいいみたい*/
		getchar();
	}

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			printf("%c", board[i][j]);
		}
		printf("\n");
	}

	return 0;
}
