#include <stdio.h>

int main(void)
{
	char s[11];
	int i, a, b;
	int j = 0;
	int flag = 0;
	int num[3];
	
	scanf("%s", s);
	a = sizeof(s) / sizeof(s[0]); //要素の個数

	for (i = 0; i < a; ++i)
	{
		if (s[i]) == '0'){
			num[j] = s[i];
			flag++;
		}
		else if(s[i] == '1'){
			num[j] = s[i];
			flag++;
		}
		else if(s[i] == '2'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '3'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '4'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '5'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '6'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '7'){
			num [j] = s[i];
			flag++;
		}
		else if(s[i] == '8'){
			num [j] = s[i];
			flag++;
		}
		else(s[i] == '9'){
			num [j] = s[i];
			flag++;
		}

		if (flag == 1)
			j++;

	}

	b = 10 * num[0] + num[1];
	printf("%d\n", b);

	return 0;
}