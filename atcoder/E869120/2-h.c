#include <stdio.h>

int main(void)
{
	int n, Q;
	int q[100001];
	int l[100001];
	int r[100001];
	int flag[100001] = {0};
	int count = 0;
	int i, j, k, z;

	scanf("%d %d", &n, &Q);
	for (k = 0; k < Q; ++k)
	{
		scanf("%d %d %d", &q[k], &l[k], &r[k]);
	}


	for (i = 0; i < Q; ++i)
	{
		if (q[i] == 1)
		{
			for (j = l[i]; j < r[i]; ++j)
			{
				if (flag[j] == 0)
				{
					flag[j] = 1;
				}else{
					flag[j] = 0;
				}
			}
		}else{
			for (int z = l[i]; z < r[i]; ++z)
			{
				if (flag[z] == 1)
				{
					count++;
				}
			}
			printf("%d\n", count);
			count = 0;
		}
	}
	return 0;
}