#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
 
int main(void){
	ll n, s; cin >> n >> s;
	ll ans = 0;
 
	if(n > s && s == 1){
		printf("%lld\n", n);
		return 0;
	}
	for (ll b = 10; b <= n; b *= 10){
		ll ans = 0;
		ll tmpn = n;
		while(1){
			if(tmpn < b){
				break;				
			}
			ans += tmpn % b;
			tmpn =  floor(tmpn / b);
		}
		ans += tmpn;
		if(ans == s){
			printf("%lld\n", b);
			return 0;
		}
	}
	for (ll b = 8; b <= n; b *= 8){
		ll ans = 0;
		ll tmpn = n;
		while(1){
			if(tmpn < b){
				break;				
			}
			ans += tmpn % b;
			tmpn =  floor(tmpn / b);
		}
		ans += tmpn;
		if(ans == s){
			printf("%lld\n", b);
			return 0;
		}
	}
	for (ll b = 16; b <= n; b *= 16){
		ll ans = 0;
		ll tmpn = n;
		while(1){
			if(tmpn < b){
				break;				
			}
			ans += tmpn % b;
			tmpn =  floor(tmpn / b);
		}
		ans += tmpn;
		if(ans == s){
			printf("%lld\n", b);
			return 0;
		}
	}
	printf("-1\n");
	return 0;
}