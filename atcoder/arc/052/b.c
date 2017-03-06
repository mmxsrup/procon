#include <stdio.h>

int main(void)
{
	int N, Q;
	int i, j, a, b;
	int X[10000];
	int R[10000];
	int H[10000];

	int A[100000];
	int B[100000];

	scanf("%d %d", &N, &Q);
	
	for (i = 0; i < N; ++i)
	{
		scanf("%d %d %d", &X[i], &R[i], &H[i]);
	}

	for (j = 0; j < Q; ++j)
	{
		scanf("%d %d", &A[j], &B[j])
	}

	for (k = 0; k < Q; ++k)
	{
		V = (R[k] * R[k] * H[k]) / 3;
		a = A[k] - X[k];
		b = A[k] - X[k];

		if (a < 0)
			a = 0;
		if (b < 0)
			b = 0;

		

	}
	
	return 0;
}