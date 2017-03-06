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

int c[110][110]; //C[H][W]
int brack[110][110];
int white[110][110];
int cnt = 0;
int H, W;

void slove(int h, int w){ // h,wは同じ濃度になるか判定するチョコレートの大きさ
	int sum_brack = 0;
	int sum_white = 0;
	for (int i = 0; i <= H - h; ++i)
	{
		for (int j = 0; j <= W - w; ++j)
		{
			for (int k = i; k < i + h; ++k)
			{
				for (int l = j; l < j + w; ++l)
				{
					sum_brack += brack[k][l];
					sum_white += white[k][l];
				}
			}
		}
		if (sum_brack == sum_white)
		{
			cnt = h * w; //単調増加で求めていくからただ更新するだけ
		}
	}
	return;
}

int main (void)
{

	scanf("%d %d", &H, &W);

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			scanf("%d", &c[i][j]);
		}
	}

	for (int i = 0; i < H; ++i)
	{
		for (int j = 0; j < W; ++j)
		{
			if (i % 2 == 0)
			{//偶数行
				if (j % 2 == 0)
				{//偶数行かつ偶数列
					brack[i][j] = c[i][j];
					white[i][j] = 0;
				}else{
				 //偶数行かつ奇数列
					brack[i][j] = 0;
					white[i][j] = c[i][j];
				}
			}else{
			 //奇数行
				if (j % 2 == 0)
				{//奇数行かつ偶数列
					brack[i][j] = 0;
					white[i][j] = c[i][j];
				}else{
				 //奇数行かつ奇数列
					brack[i][j] = c[i][j];
					white[i][j] = 0;
				}
			}
		}
	}

	for (int i = 1; i <= H ; ++i)
	{
		for (int j = 1; j <= W; ++j)
			slove(H, W);
	}

	printf("%d\n", cnt);

	return 0;
}