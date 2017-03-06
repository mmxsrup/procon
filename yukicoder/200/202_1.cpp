#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
static const int mod = 1e9 + 7;

int main(void){
	int n; cin >> n;
	vector<pair<int, int> > center;
	//(n^2)でout?
	rep(i, n){
		// printf("i %d\n", i);
		int cx, cy; cin >> cx >> cy;
		if(center.size() != 0){
			sort(center.begin(), center.end());//(nlogn)
			int xl = cx - 20, xr = cx + 20;
			int yl = cy - 20, yr = cy + 20;
			//(logn)
			auto it1 = lower_bound(center.begin(), center.end(), make_pair(xl, yl));
    		auto it2 = upper_bound(center.begin(), center.end(), make_pair(xr, yr));
    		bool flag = true;
    		//(n)
    		for(auto itr = it1; itr != it2; ++itr) {
        		auto p = *itr;
        		int nx = p.first, ny = p.second;
        		// printf("%d %d\n", nx, ny);
        		double len = sqrt((nx - cx) * (nx - cx) + (ny - cy) * (ny - cy));
        		// printf("len %f\n",len );
        		if(len < 20){
        			flag = false;
        			break;
        		}
    		}
    		if(flag)center.push_back(make_pair(cx, cy));
		}else{
			center.push_back(make_pair(cx, cy));
		}
	}

	printf("%d\n", (int)center.size());
	return 0;
}