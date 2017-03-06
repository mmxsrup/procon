//TLE

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
 
int main(void){
	int N;
	scanf("%d", &N);
	vector<int> color(N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &color[i]);
	}
 
	int flag = 1;
	int cnt = 0;
	vector<int> tmp_color(N);
	//配列をコピー
	while(flag == 1 && cnt < 10000){ //変更点がないとflag＝０となり抜けられる
		//flagの初期化
		flag = 0;
		for (int i = 0; i < N; ++i)
		{
			tmp_color[i] = color[i];
		}
		//真ん中が0の時の判定
		if (tmp_color[N - 1] == tmp_color[0] && tmp_color[0] == tmp_color[1])
		{
			flag = 1; //変更点があったことを示す
			if (tmp_color[0] == 1)
			{
				color[0] = 0;
			}else{
				color[0] = 1;
			}
		}
		//真ん中がn-1の時の判定
		if (tmp_color[N - 2] == tmp_color[N - 1] && tmp_color[N - 1] == tmp_color[0])
		{
			flag = 1;
			if (tmp_color[N - 1] == 1)
			{
				color[N - 1] = 0;
			}else{
				color[N - 1] = 1;
			}
		}
		//真ん中が1~N-2の時の判定
		for (int i = 1; i < N - 1 ; ++i)
		{
			if (tmp_color[i - 1] == tmp_color[i] && tmp_color[i] == tmp_color[i + 1])
			{
				flag = 1;
				if (tmp_color[i] == 1)
				{
					color[i] = 0;
				}else{
					color[i] = 1;
				}
			}
		}
		cnt++;
	}
	if (cnt < 10000)
	{
		printf("%d\n", cnt);
	}else{
		printf("-1\n");
	}
	return 0;
}