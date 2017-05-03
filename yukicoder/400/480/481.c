#include <stdio.h>

int main(void){
	int B[11];
	B[0] = 0, B[10] = 11;
	for (int i = 1; i <= 9; ++i){
		scanf("%d", &B[i]);
	}
	
	for (int i = 0; i < 10; ++i){
		if(B[i + 1] - B[i] == 2){
			printf("%d\n", i + 1);
			return 0;
		}
	}
	return 0;
}