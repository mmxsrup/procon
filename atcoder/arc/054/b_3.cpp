/*
下凸の関数になることは自明
この場合三分探索により、探索範囲を毎回2/3にしていくことで減らせる
型はdoubleでもいいみたい
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

long double P;
//関数の計算部分の関数
double func(double x){
	return x + P / pow(2.0, x / 1.5);
}
 
int main(void){
	long double ans;
	scanf("%Lf", &P);
 
	ans = 100000000;
 
	double low = 0.0, high = 1000.0; //highは十分な大きさにしておけばいい
	double l, r;
	for (int i = 0; i < 10000; ++i) //10000というのはある程ど大きな数字であればいい
	{
		l = (low * 2.0 + high) / 3.0; //内分の公式
		r = (low + high * 2.0) / 3.0; //内分の公式
		if (func(l) < func(r)){
			high = r; //大きい方まで範囲を狭めてこれる
		}else{
			low = l; //大きい方まで範囲を狭めてこれる
		}
	}

	ans = func(l); //最後により小さい方で代入する
	printf("%.9Lf\n", ans);
 
	return 0;
}