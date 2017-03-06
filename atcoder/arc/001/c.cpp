/*
全探索
はじめに与えられた３点を気にして実装が難しくなってしまった
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

char board[10][10]; //ボードの配列を作成
int kimatteru_x[5];
int kimatteru_y[5];

//(x, y)におけるかどうかをチェック
bool check(int x, int y){
	//すでに置かれてる３つではないかをチェック
	if (board[x][y] == 'Q')
	{
		return true;
	}

	//左にないかチェック
	for (int i = 0; i < x; ++i)
	{
		if (board[i][y] == 'Q')
			return false;
	}
	//右にないかチェック
	for (int i = x + 1; i < 8; ++i)
	{
		if (board[i][y] == 'Q')
			return false;
	}
	//上にないかチェック
	for (int i = 0; i < y; ++i)
	{
		if (board[x][i] == 'Q')
		{
			return false;
		}
	}
	//下にないかチェック
	for (int i = y + 1; i < 8 ; ++i)
	{
		if (board[x][i] == 'Q')
		{
			return false;
		}
	}

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

	p = x; q = y;
	//右下にないかチェック
	while(p < 7 && q < 7){
		if (board[++p][++q] == 'Q')
			return false;
	}

	p = x; q = y;
	//右上にないかチェック
	while(p < 7 && q > 0){
		if (board[++p][--q] == 'Q')
			return false;
	}

	return true;
}



bool slove(int x){
	if (x == 8)
	{
		//成功
		return true;
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
				//消してはいけないものもかく
				//board[kimatteru_x[0]][kimatteru_y[0]] = 'Q';
				//board[kimatteru_x[1]][kimatteru_y[1]] = 'Q';
				//board[kimatteru_x[2]][kimatteru_y[2]] = 'Q';
			}
		}
	}
	return false;
}


int main(void){
	int cnt = 0;
	//入力
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			scanf("%s", &board[j][i]);
			if (board[j][i] == 'Q')
			{
				kimatteru_x[cnt] = j;
				kimatteru_y[cnt] = i;
				cnt++;
			}
		}
	}

	if (slove(0)) //０列目から始めよう
	{
		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				printf("%c", board[j][i]);
			}
			printf("\n");
		}
	}else{
		printf("No Answer\n");
	}

	return 0;
}












