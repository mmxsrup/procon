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
	int L, X, Y, S, D;
	scanf("%d %d %d %d %d", &L, &X, &Y, &S, &D);

	double clock, ans, ans_right, ans_left, counterclock;

	//高橋くんの走る速度が遅ければ、時計回りにしか走れないz	
	clock = (D - S + L) % L; //時計回りの距離　modLを取ればいい　
	ans = clock / (double)(Y + X); //逆走不可能なら　そのまますすんだ方が早い
	
	// 逆走可能な時
	if (X < Y)
	{	/* 下だとエラー　doubelがたでは％は使えない*/
		//counterclock = ((S - D + L) % L);//逆時計回りの距離　modLをとる
		counterclock = (S - D + L) % L;
		ans = min(ans, counterclock / (double)(Y - X)); //時計周りと逆時計周りのどちらが早いか比較
	}

	printf("%.9f\n", ans);

	return 0;
}