#include <stdio.h>
#include <string.h>

int main(void)
{
	char s[1000];
	int k;
	int l;
	int i, j;
	int r = 0;
	char str[1000][1000];

	scanf("%s %d", s, &k);

	l = strlen(s); 

	for (i = 0; i + k <== l; i++)
	{
		strncpy(str[r], s+i , k); //strncpy str[r]にs[]の配列の+i番目からk個コピー

/* k文字列を配列に入れた後、それまでに入れた配列と比較して同じものがなければ、r == jになるので、
	rを増やして、カウントする
*/
		for (j = 0; strcmp(str[r],str[j]); j++) 
		{
			if (r == j)
			{
				r++;
			}
		}
	}

	printf("%d\n", r);
	return 0;
}