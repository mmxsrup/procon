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

	ll ans = 100000900;
	for (ll j = 1; j <= n; ++j){
		for (ll k = j; k <= n; ++k){
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