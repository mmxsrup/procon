#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;


int main(void){
	int h, w;
	int num1, num2;
	scanf("%d %d", &h, &w);

	num1 = (h - 1) * w;
	num2 = (w - 1) * h;

	printf("%d\n", num1 + num2);




	return 0;
}