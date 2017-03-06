#include <stdio.h>

int main(void)
{
	char password[5];
	scanf("%s" ,password); //scanf("%c", password) だとできない

	if (password[0] == password[1] && password[1] == password[2] && password[2] == password[3])
	{
		printf("SAME\n");	
	}
	else{
		printf("DIFFERENT\n");
	}

	return 0;
}