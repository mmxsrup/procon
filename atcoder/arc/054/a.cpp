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
	double L, X, Y, S, D;
	scanf("%lf %lf %lf %lf %lf", &L, &X, &Y, &S, &D);

	double ans_right, ans_left;
	if (D >= S)
	{
		if (X >= Y)
		{	//
			ans_right = (D - S) / (X + Y);
			ans_left = (D - S) / (X - Y);
		}else{
			ans_right = (D - S) / (X + Y);
			ans_left = (L + S - D) / (Y - X);
		}
	}else{
		if (X >= Y)
		{
			ans_right = (L - S + D) / (X + Y);
			ans_left = (L - S + D) / (X - Y);
		}else{
			//
			ans_right = (L - S + D) / (X + Y);
			ans_left = (S  - D) / (Y - X);
		}
	}

	printf("%lf\n", min(ans_right, ans_left));


	return 0;
}