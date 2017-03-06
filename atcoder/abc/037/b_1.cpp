#include <cstdio>

int main(void){
	int N, Q;
	int L[100];
	int R[100];
	long long int T[100];
	long long int a[100] = {0};

	scanf("%d %d", &N, &Q);
	for (int i = 0; i < Q; ++i)
	{
		scanf("%d %d %lld", &L[i], &R[i], &T[i]);
	}

///////////////

	for (int j = 0; j < Q; ++j)
	{
		for (int k = L[j]; k <= R[j]; ++k)
		{
			//a[k] = T[k];
			a[k - 1] = T[j];
		}
		/*
		for (int z = 0; z < N; ++z)
		{
			printf("%lld\n", a[z]);
		}
		*/
	}

/////////////

/*
	for (int z = 0; z < Q; ++z)
		{
			printf("%lld\n", T[z]);
		}
*/

	for (int l = 0; l < N; ++l)
	{
		printf("%lld\n", a[l]);
	}

	return 0;
}