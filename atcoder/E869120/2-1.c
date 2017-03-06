#include <stdio.h>
#include <string.h>

int main (void)
{
	int i, l;
	int count = 0;
	char S[100000];

	scanf("%s", S);

	l = strlen(S);

	for (i = 0; i < l; ++i)
	{
		if (count % 2 == 0.0)
		{
			if ('I' == S[i])
			{
				count++;
				i++; //したのifで正常に持って行くため
			}			
		}
		
		if (count % 2 == 1.0)
		{
			if ('O' == S[i])
			{
				count++;
			}
		}
	}

	if (count % 2 == 0.0)
	{
		printf("%d\n", count - 1);
	}else{
		printf("%d\n", count);
	}

	return 0;
}


