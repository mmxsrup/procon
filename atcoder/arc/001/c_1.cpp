/*
深さ優先探索
再帰関数
 はじめから与えられている３点は無視してまずはただ単に問題を解き、回答が出たらその答えが
 ３点を含むものかどうかを調べて同じならok
*/
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;

char board_input[10][10]; //入力用ボードの配列を作成
char board[10][10]; //slove用ボード
int kimatteru_x[5]; //決まっているQの位置を保存しておく
int kimatteru_y[5]; //決まっているQの位置を保存しておく


//(x, y)におけるかどうかをチェックする関数
bool check(int x, int y){
	//左にないかチェック
	for (int i = 0; i < x; ++i)
	{
		if (board[i][y] == 'Q')
			return false;
	}
	//右はまだない
	//上も下もない

	int p = x; 
	int q = y;

	//左上にないかチェック
	while(p > 0 && q > 0){
		if (board[--p][--q] == 'Q')
			return false;
	}

	p = x; q = y;
	//左下にないかチェック
	while(p > 0 && q < 7){
		if (board[--p][++q] == 'Q')
			return false;
	}
	return true;
}


bool slove(int x){
	if (x == 8)
	{
		//成功
		//求めた解がはじめに与えられた３点を含んでいる解なのかを求める
		if (board[kimatteru_x[0]][kimatteru_y[0]] == 'Q' && 
			board[kimatteru_x[1]][kimatteru_y[1]] == 'Q' && 
			board[kimatteru_x[2]][kimatteru_y[2]] == 'Q'){
			return true;
		}else{
			return false;
		}
	}

	for (int i = 0; i < 8; ++i)
	{
		if (check(x, i))
		{
			//(x, i)にクイーンがおける場合
			//実際に置いてみる
			board[x][i] = 'Q';
			//次の列やってみる
			if (slove(x + 1)) //次の列以降も成功なら
			{
				return true;
			}else{
				//実際に置いたものを置き直す
				board[x][i] = '.';
			}
		}
	}
	return false; //見つからなければ
}


int main(void){
	int cnt = 0;
	//入力
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			scanf("%c", &board_input[i][j]);
			if (board_input[i][j] == 'Q')
			{
				kimatteru_x[cnt] = i;
				kimatteru_y[cnt] = j;
				cnt++;
			}
		}
		getchar();
	}

	if (slove(0)) //０列目から始めよう
	{

		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("%c", board[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("No Answer\n");
	}

	return 0;
}
