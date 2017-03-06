/*
027
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

int N;
char s1[20];
char s2[20];
char string_now[20];
char alf[30] = "abcdefghijklmnopqrstuvwxyz"
int cnt[30];

int main(void){
	for (int i = 0; i < 30; ++i)
	{
		cnt[i] == 0;
	}
	scanf("%d", &N);
	getchar(); //getcharで改行を消す
	for (int i = 0; i < N; ++i)
		scanf("%c", &s1[i]);
	getchar(); //getcharで改行を消す
	for (int i = 0; i < N; ++i)
		scanf("%c", &s2[i]);

	//現状の配列をひとまずコピー
	for (int i = 0; i < N; ++i)
	{
		string_now[i] = s1[i];
	}

	char tmp;
	//s１に数字がある時
	for (int i = 0; i < N; ++i)
	{
		if (s1[i] >= '0' && s1[i] <= '9')
		{
			tmp = s2[i];
			for (int j = 0; j < N; ++j)
			{
				if (s1[j] == tmp || s2[j] == tmp)
				{
					string_now[j] = s1[i];
				}
			}
		}
	}

	//s2に数字がある
	for (int i = 0; i < N; ++i)
	{
		if (s2[i] >= '0' && s2[i] <= '9')
		{
			tmp = s1[i];
			for (int j = 0; j < N; ++j)
			{
				if (s1[j] == tmp || s2[j] == tmp)
				{
					string_now[j] = s2[i];
				}
			}
		}
	}

	//１桁目がわかっているかどうかをもとめている
	int cnt_1 = 0;
	if (string_now[0] < '0' || string_now[0] > '9')
		cnt_1++; //cnt_1 == 1なら１桁目がわかっていない
	//２桁目わかっているかどうかをもとめている
	for (int i = 1; i < N; ++i)
	{
		if (string_now[0] < '0' || string_now[0] > '9')
		{
			cnt_2++; //２桁目以降でわかっていないところの数（暫定）
		}
	}

	//それぞれのアルファベットの数を数える
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (string_now[i] == alf[j])
			{
				cnt[j]++;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (cnt[j] >= 1)
		{
			sum += (cun[j] - 1); //sumはおんじ文字を含んでいることを示すもの
		}
	}

	
	
	ll ans;
	if (cnt_1 == 1)
	{//１桁めがわかっていなくて、それも含めてわからない文字がcnt_1 + cnt_2 - sum 種類
		ans = 
	}

	printf("%lld\n", ans);

	return 0;
}