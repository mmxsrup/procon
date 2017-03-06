#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int a[1000010];

int main(void){
	int n; double p;
	cin >> n >> p;
	for (int i = 2; i <= n; ++i){//約数i
		for (int j = i * 2; j <= n; j += i){
			a[j]++;
		}
	}
	double e = 0;
	for (int i = 2; i <= n; ++i){
		e += pow((1 - p), a[i]);
	}
	printf("%.10f\n", e);
	return 0;
}