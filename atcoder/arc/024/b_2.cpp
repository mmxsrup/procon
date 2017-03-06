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
	ll cnt = 0;
	scanf("%d", &N);
	vector<int> color(N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &color[i]);
	}
	int flag = 1;
	while(flag == 1){
		cnt++;
	}
	printf("%lld\n", cnt);
	return 0;
}