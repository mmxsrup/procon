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

ll s, n;
int main(void){
	ll n; cin >> n >> s;

	
	if(n > s && s == 1){
		printf("%lld\n", n);
		return 0;
	}

	if(n < s){
		if(n == s){
			printf("%lld\n", s);
			return 0;
		}else{
			printf("-1\n");
			return 0;
		}
	}
	

	ll left = 1, right = n + 1; ll b;
	int cnt = 0;
	while(left < right && cnt < 5){
		b = (right + left) / 2;
		cnt++;
		// printf("l %lld, r %lld\n", left, right);
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
		// printf("%lld\n", ans);
		if(ans == s){
			// printf("%lld\n", b);
			return 0;
		}else if(ans < s){//bでかく
			left = b + 1;
		}else if(ans > s){//小さく
			right = b;
		}
	}

	// printf("ok\n");
	for (ll bb = left + 1; bb <= right; ++bb){
		ll anser = 0;
		ll tmpnn = n;
		// printf("bb %lld\n", bb);
		while(1){
			if(tmpnn < bb){
				break;				
			}
			anser += tmpnn % bb;
			tmpnn =  floor(tmpnn / bb);
		}
		anser += tmpnn;
		if(anser == s){
			printf("%lld\n", bb);
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}