#include <iostream>
#include <cmath>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	vector<int> d(n);
	int sum = 0, dai;
	rep(i, n){
		cin >> d[i];
		sum += d[i];
		dai = max(dai, d[i]);
	}
	if(n == 1){
		printf("%d\n", d[0]);
		printf("%d\n", d[0]);
	}else if(n == 2){
		printf("%d\n", sum);
		printf("%d\n", abs(d[0] - d[1]));
	}else{
		printf("%d\n", sum);
		//３角形の条件ぽく
		if(dai > sum - dai){//届かない
			printf("%d\n", dai - (sum - dai));
		}else{
			printf("0\n");
		}
	}
	return 0;
}