#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
	int y; cin >> y;
	if(y % 400 == 0){
		printf("YES\n");
		return 0;
	}else if(y % 100 == 0){
		printf("NO\n");
		return 0;
	}else if(y % 4 == 0){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}