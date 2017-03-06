#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
	double xa, xb, xc, ya, yb, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	xb -= xa; xc -= xa;
	yb -= ya; yc -= ya;
	//printf("%f %f %f %f\n", xb, xc, yb, yc);
	xa = 0; ya = 0;
	double s;
	s = abs(xb * yc - xc * yb) * 0.5;
	printf("%.4f\n", s);
	return 0;
}