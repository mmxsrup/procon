/*
アルゴリズム
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
	vector<int> num(5); //ここを１０とかにするとできないぞ　降順使えばいけるけど

	for (int i = 0; i < 5; ++i)
	{
		scanf("%d", &num[i]);
	}

	//だんだん大きくなるようにソート
	sort(num.begin(),num.end());

	
	//３番目に大きいのはこの２つのいずれか
	printf("%d\n", max(num[0] + num[3] + num[4], num[1] + num[2] + num[4]));

	return 0;
}