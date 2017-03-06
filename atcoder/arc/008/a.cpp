#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
	int n; cin >> n;
	int a = n * 15;
	int b = (n / 10 + 1) * 100;
	int c = (n / 10) * 100 + (n % 10) * 15;
	printf("%d\n", min(a, min(b, c)));
	return 0;
}