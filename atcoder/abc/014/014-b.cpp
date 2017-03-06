/*
全探索

ビット演算も使える
*/

#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
using namespace std;

typedef long long ll;

int main(void){
	int N, X_10, X_2;
	int a[30];
	string str;
	int sum = 0;

	//入力
	scanf("%d %d",&N, &X_10);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		if (X_10 % 2 == 1)
		{
			sum += a[i];
		}
		X_10 /= 2;
	}

/*
	//２進数へ
	X_2 = bitset<8>(X_10);

	//２進数を文字列に
	str = to_string(X_2);

	for (int i = 0; i < N; ++i)
	{
		if (str[i] == '1')//文字で比較する
		{
			sum += a[i];
		}
	}
*/
	printf("%d\n", sum);

	return 0;
}