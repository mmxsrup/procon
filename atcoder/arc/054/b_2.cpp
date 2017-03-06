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
 
	for (double x = 0; x < 200; x += 0.0001) //x< 1000とかは 0.01ずつあげていいくとなかなかたどり着かない
	{
		tmp = (P / pow(2.0, x / 1.5)) + x;
		ans = min(ans, tmp);
	}
 
	printf("%.9Lf\n", ans);
 
	return 0;
}