#include <stdio.h>

int main(void){
	int A, B, C, min;
	int count = 0;

	scanf("%d %d %d", &A, &B, &C);

	if (A >= B)
	{
		min = B;
	}else{
		min = A;
	}

	while(C >= min){
		count++;
		C -= min;
	}

	printf("%d\n", count);

	return 0;
}