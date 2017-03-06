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
 
	for (i = 0; i < n; i++){
		if (p[i] > sum / 2) {
			printf("%s\n", s[i]);
			return 0; //帰り値を返せば関数を終えられる
		}	
 	}
 	printf("atcoder\n");

	return 0;
}