#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
using namespace std;

typedef long long ll;


ll N;
int main(void){
	scanf("%lld", &N);
	int count_1 = 0;

	for (int i = 1; i <= N; ++i)
	{
		string s;
		s = to_string(i);
		
		for (int j = 0; j < s.length(); ++j)
		{
			if (s[j] == '1')
			{
				count_1++;
			}
		}
	}

	printf("%d\n", count_1);
	return 0;
}


/*
実験用コード
int main(void){
	string str;
	str = "a12345";
	printf("%d\n", str[0]);
	printf("%d\n", str[1]);
	printf("%d\n", str[2]);
	printf("%d\n", str[3]);
	return 0;
}

このプログラムでは正しい数字は表示されない
しかし
s[j] == '1'
のようにどちらも文字列（文字）として扱えば比較するだけのことはできる？？？

*/


