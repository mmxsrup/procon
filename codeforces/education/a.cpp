#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main(void){
	string s; cin >> s;
	int w = s[0] - 'a';
	int h = s[1] - '1';
	int ans = 0;
	for (int i = 0; i < 8; ++i){
		int nowy = h + dy[i], nowx = w + dx[i];
		if(0 <= nowy&&nowy<= 7 && 0 <= nowx && nowx <= 7){
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}