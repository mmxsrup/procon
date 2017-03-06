#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
	int n, m, c; cin >> n >> m >> c;

	if(n == 1 || m == 1){
		if(n == 1 && m == 2){//←気付けない
			printf("YES\n");
			return 0;
		}
		if(n == 2 && m == 1){
			printf("YES\n");
			return 0;
		}
		printf("NO\n"); return 0;
	}

	if((n * m) % 2 == 0){
		printf("YES\n");
		return 0;
	}
	printf("NO\n");
	return 0;
}