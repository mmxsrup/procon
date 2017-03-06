#include <stdio.h>

int main (void)
{
	int a, b, n ,x, LCG;
	int tmp;

	scanf("%d" ,&a);
	scanf("%d", &b);
	scanf("%d", &n);

	x = a * b;

	if (a < b){
		tmp = a;
		a = b;
		b = tmp;
	}
	// aの方を大きくする bの方が小さい
	

	int r = a % b;
	while(r != 0){
		a = b;
		b = r;
		r = a % b;
	}
	//　ユークリットの互除法で最大公約数はb

	LCG = x / b;

	while (LCG < n){
		LCG *= 2;
	}
	
	printf("%d\n", LCG);

	return 0;
}