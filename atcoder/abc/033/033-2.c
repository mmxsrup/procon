#include <stdio.h>
#include <string.h> //strcpyを利用するため

int main (void)
{
	int N, max, add;
	int i, j, k;
	char S[1001][21];
	int P[1001];
	scanf("%d", &N);

	for (i = 0; i < N; ++i)
	{
		scanf("%s", S[i]);
		scanf("%d", &P[i]);
	}

	max = P[0];
	char str[21];
	strcpy(str, S[0]);

	for (j = 0; j < N; ++j)
	{
		if (P[j] < P[j + 1])
		{
			max = P[j + 1];
			strcpy(str, S[j + 1]);
		}
	}

	for (k = 0; k < N; ++k)
	{
		add += P[k];
	}

	if (max > (add / 2))
	{
		printf("%s\n", str);
	}else{
		printf("atcoder\n");
	}

	return 0;
}

/*
#include <stdio.h>
 
char s[1000][21];
int p[1000];
 
int main(void) {
	int i;
	int n;
	int sum;
 
	scanf("%d", &n);
	sum = 0;
	for (i = 0; i < n; i++) {
		scanf("%s %d", s[i], &p[i]);
		sum += p[i];
	}
 
	for (i = 0; i < n; i++)
		if (p[i] > sum / 2) {
			puts(s[i]);
		}else
 
	puts("atcoder");
 
	return 0;
}
*/