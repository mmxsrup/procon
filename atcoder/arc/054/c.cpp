/*

行列の
話らしいけどわからん
*/
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

int N;
int s[200][200];
int main(void){
	char S_input[201][201];
	scanf("%d", &N);

/************************************
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", S_input[i]);
	}
/*************************************/

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (S_input[i][j] == '0')
				s[i][j] = 0;
			else
				s[i][j] = 1;
		}
	}

	for (int i = 0; i < N; ++i){
		int flag = -1;
		//i列目で全部が０以外の要素がある行を探す
		//存在しなければ、行列式＝０
		for (int j = 0; j < N; ++j){
			if (s[j][i] != 0)// s[行][列]
			{
				flag = j;
				break;
			}
		}
		//flagが更新されずにループが終了したら、行列式=0ということ
		if (flag == 1){
			printf("Even\n");
			return 0;
		}


	}


	return 0;
}












