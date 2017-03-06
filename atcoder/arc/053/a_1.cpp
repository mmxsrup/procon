
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int main(void){
	int len; //文字列の長さを入れる変数
	string tmp;
	char s[100010];
	char alf[30] = "abcdefghijklmnopqrstuvwxyz"; //アルファベット表を作成
	int count[30]; //a~zからの文字の数を入れておく配列

	int yobun = 0; //組が作れないものの数
	int kumi; //組ができるものの組の数

	//入力
	scanf("%s", s);

	//入力文字数の計算
	tmp = s;
	len = tmp.length();

	 //それぞれの文字が何個あるか計算
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < len; ++j)
		{
	 		if (alf[i] == s[j]) //アルファベット表と比較
	 		{
	 			count[i] += 1; //見つけたら＋１
	 		}
	 	}
	 }

	for (int i = 0; i < 26; ++i)
	{
		if (count[i] % 2 == 1)
		{
	 		yobun++; //組が作れない文字の数を計算
	 	}
	}
	kumi = (len - yobun) / 2;

	int ans;

	if (kumi == 0) //組が作れない時回文は作れないので１つずつの文字になる
	{
	 	ans = 1;
	 }else if(yobun == 0){ //奇数がないとき全ての文字で組ができる
	 	ans = len; //ans = kumi * 2
	 }else{ //(kumi / yobun)で少数点以下を捨てる
	 	ans = (kumi / yobun) * 2 + 1; //+1は組が出来ないものを加える
	}

	//出力
	printf("%d\n", ans);

	return 0;
}