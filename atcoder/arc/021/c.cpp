#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

typedef long long ll;

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int K, N;
int AD[101010][3];
ll sum = 0;

void slove(void){
	int min = AD[0][0];
	int min_A = 0;

	//現在の価格の最小値を見つける
	for (int i = 1; i < N; ++i)
	{
		if (min > AD[i][0])
		{
			min = AD[i][0];
			min_A = i;
		}
	}
	sum += min;
	//価格表の更新
	AD[min_A][0] += AD[min_A][1]; 

	return;
}


int main(void){

	scanf("%d %d", &K, &N);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 2; ++j)
			scanf("%d", &AD[i][j]);
	}

	for (int i = 0; i < K; ++i)
		slove();

	printf("%lld\n", sum);
	return 0;
}