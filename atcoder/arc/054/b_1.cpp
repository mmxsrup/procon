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
	long double P, ans, tmp;
	scanf("%Lf", &P);
 
	ans = 100000000;
 
	for (long double x = 0; x < 1000; x+= 0.0001)
	{
		tmp = (P / pow(2.00000, x / 1.500000)) + x;
		ans = min(ans, tmp);
	}
 
	printf("%08.8Lf\n", ans);
 
	return 0;
}