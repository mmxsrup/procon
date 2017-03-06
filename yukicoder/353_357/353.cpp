
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;


int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int a, b;
	cin >> a >> b;

	int ma = max(a, b);
	int mi = min(a, b);
	int ans = (ma*2) - (ma - mi);
	printf("%d\n", ans);
	return 0;
}