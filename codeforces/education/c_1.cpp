#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int b[60][60];
int main(void){
	rep(i, 60)rep(j, 60) b[i][j] = 0;
	int n; cin >> n;

	int kado = sqrt((n * n - (n*2 - 1)) / 4) - 1;
	int kisuu = 1;
	int guusu = 2;
	rep(i, n){
		b[i][n / 2] = kisuu; kisuu += 2;
	}
	rep(i, n){
		if(i == n / 2) continue;
		b[n / 2][i] = kisuu; kisuu += 2;
	}

	int now = kado;
	rep(i, kado){
		rep(j, now){
			b[i][j] = kisuu; kisuu += 2;
		}
		now--;
	}

	now = kado;
	for (int i = n - 1; i > n - 1 - kado ; --i){
		rep(j, now){
			b[i][j] = kisuu; kisuu += 2;
		}
		now--;
	}

	now = kado;
	rep(i, kado){
		for (int j = n - 1; j > n - 1 - now ; --j){
			b[i][j] = kisuu; kisuu += 2;
		}
		now--;
	}

	now = kado;
	for (int i = n - 1; i > n - 1 - kado ; --i){
		for (int j = n - 1; j > n - 1 - now ; --j){
			b[i][j] = kisuu; kisuu += 2;
		}
		now--;
	}

	rep(i, n)rep(j, n){
		if(b[i][j] == 0){
			b[i][j] = guusu;
			guusu += 2;
		}
	}

	rep(i, n){
		rep(j, n){
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}