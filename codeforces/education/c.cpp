#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int b[50][50];
int main(void){
	int n; cin >> n;
	int odd = n / 2 + 1;
	int kado = (odd - (n * 2 - 1)) / 8;
	int kisuu = 1;
	int guusu = 2;
	for (int i = 0; i < n; ++i){
		if(0 <= i && i < kado){
			rep(j, n){
				if(0 <= j && j < kado){
					b[i][j] = kisuu; kisuu += 2;
				}
				if(j == kado || j == kado + 2){
					b[i][j] = guusu; guusu += 2;
				}
				if(j == kado + 1){
					b[i][j] = kisuu; kisuu += 2;
				}
				if(j > kado + 2){
					b[i][j] = kisuu; kisuu += 2;
				}
			}
		}
		if(i == kado){

		}
		if(i == kado + 1){

		}
		if(i == kado + 2){

		}
		if(i > kado + 2){

		}
	}
	return 0;
}