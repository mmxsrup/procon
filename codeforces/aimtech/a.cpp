#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(void){
	int n, b, d;
	cin >> n >> b >> d;
	int sum = 0, ans = 0;
	rep(i, n){
		int tmp; cin >> tmp;
		if(tmp > b) continue;
		sum += tmp;
		if(sum > d){
			ans++; sum = 0;
		}
	}
	cout << ans << endl;
	return 0;
}