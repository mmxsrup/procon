#include <stdio.h>

int main(void){

	int i, j, k, l;
	int N;
	int Q;
	int L[100];
	int R[100];
	long int T[100];
	long int a[100] = {0};

	scanf("%d %d", &N, &Q);

	for (i = 0; i <= Q - 1; i++)
	{
		scanf("%d %d %ld", &L[i], &R[i], &T[i]);
	}

	for (j = 0; j < Q; ++j)
	{
		for (k = L[j] - 1; k <= R[j] - 1; ++k)
		{
			a[k] = T[k];
		}
	}
	
	for (l = 0; l < N; ++l)
	{
		printf("%ld\n", a[l]);
	}

	return 0;
}