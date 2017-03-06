#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(void){
	int d; cin >> d;
	int tmp = d / 2;
	int ans = 0;
	for (int i = 1; i < tmp; ++i){
		int l = i, r = tmp - i;
		ans = max(l * r, ans);
	}
	cout << ans << endl;
}