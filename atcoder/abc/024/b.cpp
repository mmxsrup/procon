/*
bigginer 24 -B

TLE食らった
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
#include <queue>
using namespace std;

typedef long long ll;

int main(void){
	int N, T;

	scanf("%d %d", &N, &T);
	//人が通った時間を配列に入れる
	int a[1010101];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}

	//open配列　１：空いてる　０；閉じてる
	vector<int> open(1100010, 0); //要素1200000個を０で初期化

	
	for (int i = 0; i < N; ++i)
	{
		for (int j = a[i]; j < a[i] + T; ++j)
		{
			open[j - 1] = 1;
		}
	}

	ll cnt = 0;
	for (int i = 0; i < 1100010; ++i)
	{
		if (open[i] == 1)
			cnt++;
	}
	
	printf("%lld\n", cnt);

	return 0;
}