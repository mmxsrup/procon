/*
026
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
	ll N;
	ll sum = 0;

	scanf("%lld", &N);

	for (int i = 1; i <= N / 2; ++i)
	{
		if (N % i == 0)
		{
			sum += i;
		}
	}

	if (N == sum)
	{
		printf("Perfect\n");
	}else if(N < sum){
		printf("Abundant\n");
	}else{
		printf("Deficient\n");
	}
	
	return 0;
}
