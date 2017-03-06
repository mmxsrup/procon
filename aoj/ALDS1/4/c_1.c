#include <stdio.h>
#include <string.h>

int main(void)
{
    int len;
    char s[100] = "today";

    len = strlen(s);
    printf("\"%s\" は %d 文字\n", s, len);

    printf("\"%s\" は %lu 文字\n", "hello world", strlen("hello world"));

    return 0;
}