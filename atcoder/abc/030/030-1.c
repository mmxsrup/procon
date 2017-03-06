#include <stdio.h>

int main(void)
{
	int A, B, C, D;
	double winT, winA;
	scanf("%d %d %d %d", &A, &B, &C, &D);

	winT = (double)B / (double)A;
	winA = (double)D / (double)C;
	

	if (winT > winA)
		printf("TAKAHASHI\n");
	else if(winT == winA)
		printf("DRAW\n");
	else
		printf("AOKI\n");

	return 0;
}
