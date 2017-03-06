#include <stdio.h>

int main (void)
{
	long long int n;
	long long int num[10000000000001];
	int q;
	int a[25];

	int i, j, k;
	long long int l, m;
	long long int count = 0;

	scanf("%lld %d", &n, &q);

	for (int l = 0; l < n; ++l)
	{
		num[l] = l + 1;
	}

	for (i = 0; i < q; ++i)
	{
		scanf("%d", &a[i]);
	}

	for (j = 0; j < q; ++j)
	{
		for (int k = 0; k < n; ++k)
		{
			if (num[k] % a[j] == 0)
			{
				num[k] = num[k] / a[j];
			}
		}
	}

	for (m = 0; m < n; ++m)
	{
		if (num[m] == 1)
		{
			count++;
		}
	}

	printf("%lld\n", count);
	return 0;
}