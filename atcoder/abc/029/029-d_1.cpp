#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
using namespace std;

typedef long long ll;


int main(void){
	//入力
	ll N;
	scanf("%lld", &N);

	//桁数を数える
	ll number = N;
	int keta = 0;
	while(number!=0){
    number = number / 10;
    keta++;
	}
/*-----------------------------------*/

	//循環回数と循環のどこまで行っているかを調べる
	ll kai[30];
	ll amari[30];
	ll tmp_1, tmp_2;
	ll jyunkan = 10;
	for (int i = 0; i < keta; ++i)
	{
		tmp_1 = N;
		tmp_2 = N;
		//循環回数
		kai[i] = tmp_1 / jyunkan;
		//１回の循環でどこまで進んでるか
		amari[i] = tmp_2 % jyunkan;
		//循環のサークルが１０倍へ
		jyunkan *= 10;
	}

/*
	for (int i = 0; i < keta; ++i)
	{
		printf("%lld %lld\n", kai[i], amari[i]);
	}
*/

	/*1が何個あるかを調べる*/
	ll cnt = 0;
	//１のけたは注意
	if (amari[0] != 0)
	{
		cnt = kai[0] + 1;
	}else{
		cnt = kai[0];
	}

	//10~のけた
	ll jyunkan_new = 10;
	ll add = 0;
	for (int i = 1; i < keta; ++i)
	{
		//しっかり循環している部分からわかる１
		cnt += kai[i] * jyunkan_new;
		//循環が途中で終わってしまっているところからわかる１
		if (amari[i] - jyunkan_new > 0)
		{
			if (amari[i] - jyunkan_new >= jyunkan_new)
			{
				add = jyunkan_new;
			}else{
				add = amari[i] - jyunkan_new;
			}
		}
		cnt += add;
		add = 0;
		jyunkan_new *= 10;
	}

	printf("%lld\n", cnt);

	return 0;
}

