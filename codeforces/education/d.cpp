#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n; cin >> n;
	int x, y; cin >> x >> y;
	long long now = 0;
	long long time = 0;
	while(now < n){
		if(n - now < now){//コピー不可
			// printf("1 %lld %lld\n", now, time);
			time += (n - now) * x;
			now = n;
		}else{//コピー可
			if((double)x  < (double)y / (double)now || now == 0){//1枚の方が安い
				// printf("2 %lld %lld\n", now, time);
				time += x;
				now += 1;
			}else{
				// printf("3 %lld %lld\n", now, time);
				time += y;
				now *= 2;
			}
		}
	}
	cout << time << endl;
	return 0;
}