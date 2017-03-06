#include <stdio.h>

int main(void)
{
	long long int R, B;
	long long int r, b;
	long long int x, y;
	int i = 0;
	int j = 0;

	scanf("%lld %lld", &R, &B);
	scanf("%lld %lld", &x, &y);

	do{
		r = R - x;
		b = B - 1;
		i++
	}while(r >= x && b >= 1);

	do{
		r = R - 1;
		b = B - y
		j++;
	}while(r >= 1 && b >= y);
	


}