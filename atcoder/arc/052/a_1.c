#include <stdio.h>

int main(void)
{
int i = 0;
char s[256];

scanf("%s",s);

while(s[i]!='\0'){
if(s[i]>='0' && s[i]<='9')printf("%c",s[i]);
i++;
}
printf("\n");

return 0;
}