#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main(void){
	string s; cin >> s;
	int n = s.size();

	//連続した２文字を見る
	for (int i = 0; i < n - 1; ++i){
		if(s[i] == s[i + 1]){
			printf("%d %d\n", i + 1, i + 1 + 1); return 0;
		}
	}

	//a*aのような文字列
	for (int i = 1; i < n - 1; ++i){
		if(s[i - 1] == s[i + 1]){
			printf("%d %d\n", i - 1 + 1, i + 1 + 1); return 0;
		}
	}

	printf("-1 -1\n");
	return 0;
}