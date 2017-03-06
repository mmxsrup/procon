/*
下凸関数だから、三分探索で探索範囲を２/3にしていける
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

int main(void){
	long double P, ans, tmp, x;
	scanf("%Lf", &P);

	ans = 100000000;


	for (long double x = 0; x < 100; x += 0.000010000)
	{
		tmp = (P / pow(2.00000, x / 1.500000)) + x;
		ans = min(ans, tmp);
	}

	/*
	while(x < 100){
		tmp = (P / pow(2.0000000, x / 1.5000000)) + x;
		ans = min(ans, tmp);
		x += 0.00010000;
	}
	*/

	printf("%08.8Lf\n", ans);

	return 0;
}