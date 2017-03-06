#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)

//positionbit目が立っているか判定
bool contain(int mask, int position){
    if((mask & (1 << position)) != 0) return true;
    else return false;
}

int main(void){
	string s; cin >> s;
	int n = s.size() - 1;
	
	ll sum = 0;
	for(int mask = 0; mask < (1 << n); ++mask){
		int l = 0;//左端
		ll tmp = 0;
		int r;//右端
        for (r = 0; r < n; ++r){
            if(contain(mask, r)){
            	string t = s.substr(l, r - l + 1);
            	ll num = stoll(t);
            	tmp += num;
            	l = r + 1;
            }
        }
        string t = s.substr(l, r - l + 1);
        ll num = stoll(t);
        tmp += num;
        sum += tmp;
    }
    printf("%lld\n", sum);
	return 0;
}