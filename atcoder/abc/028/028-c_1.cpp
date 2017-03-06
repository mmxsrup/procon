/*
アルゴリズム
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
	int n[5];
	vector<int> date(10);
	int cnt = 0;
	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &n[i]);
	}

	for(int i = 0; i < 5; i++)
	{
		for(int j = i + 1; j < 5; j++)
		{
			for(int k = j + 1; k < 5; k++)
			{
				//合計を出す
				date[cnt] = n[i] + n[j] + n[k];
				cnt++;
			}
		}
	}

	//大きい順にソート
	sort(date.begin(),date.end(),greater<int>());

	//３番目の大きいものの大きさを求める
	//合計値が同じ場合もあり得る
 	int now = date[0];
 	int cnt_1 = 1;
	for (int i = 1; i < 10; ++i)
	{
		if (now != date[i])
		{
			now = date[i];
			cnt_1++; //1つ大きいのを見つけたことを示すフラグ
		}

		if (cnt_1 == 3)//３番目に大きいのを見つけたといこと
		{
			printf("%d\n", now);
			break;
		}
	}

	return 0;

}