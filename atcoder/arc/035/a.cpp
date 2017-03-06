#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	string s; cin >> s;
	int n = s.size();
	if(n % 2 == 0){
		for (int i = 0; i < n / 2; ++i){
			if(s[i] == s[n - i - 1] || s[i] == '*' || s[n - i - 1] == '*'){

			}else{
				printf("NO\n");
				return 0;
			}
		}
	}else{
		for (int i = 0; i < n / 2; ++i){
			if(s[i] == s[n - i - 1] || s[i] == '*' || s[n - i - 1] == '*'){

			}else{
				printf("NO\n");
				return 0;
			}
		}
	}
	printf("YES\n");
	return 0;
}