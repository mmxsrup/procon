#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
const int INF = 1e9;
const ll mod = 1e9 + 7;

string moto;
int containt(string a){
	int ret = 0;
	if(a.size() > moto.size()) return ret;
	ll t = 1;
	rep(i, a.size()){
		t *= mod;
	}
	ll hasha = 0, hashmoto = 0;
	rep(i, a.size()){
		hasha = hasha * mod + a[i];
		hashmoto = hashmoto * mod + moto[i];
	}

	for (int i = 0; i + a.size() <= moto.size(); ++i){
		if(hasha == hashmoto) ret++;
		hashmoto= hashmoto * mod + moto[i + a.size()] - moto[i] * t;
	}
	return ret;
}

int main(void){
	cin >> moto;
	int n; cin >> n;
	int ans = 0;
	rep(i, n){
		string s; cin >> s;
		ans += containt(s);
	}
	printf("%d\n", ans);
	return 0;
}