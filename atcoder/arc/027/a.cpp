/*

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
	int h, min, ans;
	scanf("%d %d", &h, &min);
	ans = ((18 - h) * 60) + (0 - min);
	printf("%d\n", ans);
	return 0;
}

