#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int a, b, c, k;
	cin >> a >> b >> c >> k;
	int s, t; cin >> s >> t;
	if(s + t >= k){
		a -= c;
		b -= c;
	}

	printf("%d\n", a * s + b * t);
	return 0;
}