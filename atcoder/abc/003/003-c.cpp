/*
sort
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
using namespace std;

typedef long long ll;

int main(void){
	int N, K;
	double c = 0; //高橋くんのレート
	
	//配列を作る
	vector<double> R(N);
	//入力
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; ++i)
	{
		scanf("%lf", &R[i]);
	}

	//降順にそーと
	sort(R.begin(), R.end(), greater<double>());

	for (int i = 0; i < K; ++i)
	{
		//必要な分を大きい方から選び、さらにその中の小さい方から足していけばいい
		c = (c + R[K - i - 1]) / 2;
	}

	printf("%lf\n", c);

	return 0;
}