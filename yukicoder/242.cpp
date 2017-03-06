#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	double n; cin >> n;
	double E = 1;
	rep(i, 5){
		E *= (n - i) / (99.0 - i);
	}
	printf("%.10f\n", E * 12);
	return 0;
}