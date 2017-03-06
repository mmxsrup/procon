/*
二分探索
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

int main(void){
	int R, C, K; //K目標
	int N;
	int date_r[101010], date_c[101010]; //元データ
	int r_sum[101010] = {0}; //横のデータの和
	int c_sum[101010] = {0}; //縦のデータの和
	int r_sum_num[101010] = {0}; //横データの和を和の大きさ別の数で
	int c_sum_num[101010] = {0}; //縦データの和の和の大きさ別の数で
	int date_sum[101010][101010] = {0}; //データの和

//入力
	scanf("%d %d %d", &R, &C, &K);
	scanf("%d", &N); //nこの飴
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d", &date_r[i], &date_c[i]);
	}

	//縦列の和を表す配列を作成
	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (date_c[j] == i)
			{
				c_sum[i]++;
			}
		}
	}
	//縦の和を区別する
	for (int i = 0; i <= R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (c_sum[j] == i)
			{
				c_sum_num[i]++;
			}
		}
	}

	//横列の和を表す配列を作成
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (date_r[j] == i)
			{
				r_sum[i]++;
			}
		}
	}
	//横の和を区別する
	for (int i = 0; i <= C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			if (r_sum[j] == i)
			{
				r_sum_num[i]++;
			}
		}
	}

	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			date_sum[i][j] == r_sum[i] + c_sum[j];
		}
	}

	//単純に和がKになるものを探す
	int sum = 0;
	

	





//和がKであるが、その地点に飴があり実質K−１の時


//我がK＋１であるが、その地点に飴がある時実質K



	return 0;
}