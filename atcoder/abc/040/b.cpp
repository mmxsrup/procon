#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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
	ll n; cin >> n;
	ll i = 0;
	ll a;
	while(i * i < n){
		a = i;
		i++;
	}
	ll b = i;
	//printf("%lld %lld\n", a, b);

	ll ans = 1000000900;
	for (int j = a / 2; j <= b * 2; ++j){
		for (int k = j; k <= b * 2; ++k){
			int sa = abs(k - j);
			int amari = n - (k * j);
			if(amari < 0) continue;
			ll sum = (sa + amari);
			//printf("%lld %lld\n", j, k);
			ans = min(sum, ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
}