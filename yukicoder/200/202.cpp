#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
static const int mod = 1e9 + 7;

bool x[30000], y[30000];
int main(void){
	rep(i, 30000) x[i] = y[i] = false;
	int n; cin >> n;
	int ans = 0;
	bool flag1 = true, flag2 = true;//seikou
	rep(i, n){
		flag1 = flag2 = true;
		int nx, ny; cin >> nx >> ny;
		int xl = max(0, nx - 9);
		int xr = nx + 9;
		int yl = max(0, ny - 9);
		int yr = ny + 9;
		// printf("%d %d\n", xl, xr);
		for (int j = xl; j <= xr; ++j){
			if(x[j] == true){
				printf("out %d\n", j);
				flag1 = false;
			}
		}
		// printf("%d %d\n", yl, yr);
		for (int j = yl; j <= yr; ++j){
			if(y[j]){
				flag2 = false;
			}
		}

		if(flag1 || flag2){
			// printf("%d\n", i);
			ans++;
			for (int j = xl; j <= xr; ++j){
				x[j] = true;
			}
			for (int j = yl; j <= yr; ++j){
				y[j] = true;
			}
		}
	}

	printf("%d\n", ans);
	return 0;
}