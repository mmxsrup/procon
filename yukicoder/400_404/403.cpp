#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

const int mod = 1e9 + 7;
int main(void){
	ll a, b, c;
	string s; cin >> s;
	int l = 0, cnt = 0;
	for (int i = 0; i < s.size(); ++i){
		if(s[i] != '^' && i != s.size() - 1) continue;
		else{
			if(i == s.size() - 1) i++;
			string tmp = s.substr(l, i - l);
			if(cnt == 0)a = stod(tmp);
			else if(cnt == 1) b = stod(tmp);
			else c = stod(tmp);
			cnt++; l = i + 1;
		}
	}

	long long ans1tmp = 1, ans1 = 1;
	rep(i, b){
		ans1tmp *= (a % mod);
		ans1tmp %= mod;
	}
	rep(i, c){
		ans1 *= (ans1tmp % mod);
		ans1 %= mod;
	}
	printf("gg%lld\n", ans1 % mod);

	long long ans2tmp = 1, ans2 = 1;
	rep(i, c){
		ans2tmp *= (b % mod);
		ans2tmp %= mod;
	}
	rep(i, a){
		ans2 *= (ans2tmp % mod);
		ans2 %= mod;
	}

	printf("%lld %lld\n", ans1 % mod, ans2 % mod);
	return 0;
}