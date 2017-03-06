#include <iostream>
#include <cstdio>
using namespace std;

string s[3];
int main(void){
	cin >> s[0] >> s[1] >> s[2];
	int now = 0;
	while(1){
		if(s[now].size() == 0){
			if(now == 0) printf("A\n");
			else if(now == 1) printf("B\n");
			else if(now == 2) printf("C\n");
			return 0;
		}
		int tmp = now;
		if(s[now][0] == 'a'){
			now = 0;
		}else if(s[now][0] == 'b'){
			now = 1;
		}else if(s[now][0] == 'c'){
			now = 2;
		}
		s[tmp].erase(s[tmp].begin());
	}
}