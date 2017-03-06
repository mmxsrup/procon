/*
データ構造
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
	int N;
	scanf("%d", &N);
	//配列を用意
	vector<ll> a(N);

	//データを入力
	for (int i = 0; i < N; ++i)
	{
		scanf("%lld", &a[i]);
	}

	//奇数で割る
	for (int i = 0; i < N; ++i)
	{
		while(a[i] % 2 == 0){
			a[i] /= 2;
		}
	}

	//そーと
	sort(a.begin(),a.end());

	//違うものの個数を数得る
	ll cnt = 1;
	ll now = a[0];
	for (int i = 1; i < N; ++i)
	{
		if (now != a[i])
		{
			now = a[i];
			cnt++;
		}
	}
	printf("%lld\n", cnt);

	return 0;
}