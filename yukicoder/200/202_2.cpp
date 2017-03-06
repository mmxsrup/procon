#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
static const int mod = 1e9 + 7;

vector<int> center[20100];

int main(void){
	int n; cin >> n;
	int ans = 0;
	rep(i, n){
		int cx, cy; cin >> cx >> cy;
		int xl = max(0, cx - 20);
		int xr = cx + 20;
		bool flag = true;
		for (int nx = xl; nx <= xr; ++nx){
			for(auto ny : center[nx]){
				double len = sqrt((nx - cx) * (nx - cx) + (ny - cy) * (ny - cy));
        		// printf("len %f\n",len );
        		if(len < 20){
        			flag = false;
        			break;
        		}
			}
		}
		if(flag){
			ans++;
			center[cx].push_back(cy);
		}
	}

	printf("%d\n", ans);
	return 0;
}