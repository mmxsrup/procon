#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d", &n);

	if (n % 2 == 0){
		printf("%d\n", n - 1);
	}
	else{
		printf("%d\n", n + 1);
	}

	return 0;
}