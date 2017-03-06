/*
尺取り法
頻度を計算して、２つ以上含まれる数字がないかを調べる
1部TLE
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
int A[100010];
int N;

bool slove(int L, int R){
	int db[100010] = {0};
	for (int i = L; i <= R; ++i)
	{
		db[A[i]]++;
		if (db[A[i]] > 1) //２つ以上含まれているものがあればその区間はダメ
			return false;
	}
	return true;
}

int main(void){
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}

	int ans = 1;
	int l = 0;//left 配列の添字に合わせている
	/* まずは同じ数が２つ含まれるまでrを大きくしていく*/
	for (int r = 0; r < N; ++r) //rはN - 1まで
	{ /* 同じ文字が二つ含まれている間はlを大きくしていく*/
		while(slove(l, r) == false)
			l++;
	
		ans = max(ans, r - l + 1); //２つ含まれない長さが見つかったら、答えを更新していく
	}
	printf("%d\n", ans);
	return 0;
}


