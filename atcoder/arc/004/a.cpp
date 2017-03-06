#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

double x[110], y[110];
int main(void){
	int n; cin >> n;
	rep(i, n){
		cin >> x[i] >> y[i];
	}

	double ans = 0.0;
	rep(i, n)rep(j, n){
		if(i == j) continue;
		double l = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
		ans = max(ans, sqrt(l));
	}
	printf("%.9f\n", ans);
	return 0;
}