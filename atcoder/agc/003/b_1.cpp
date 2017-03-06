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

ll a[200100];
int main(void){
	ll n; cin >> n;
	ll ans = 0;
	rep(i, n){
		ll tmp; cin >> tmp;
		// ans += tmp / 2;
		a[i] = tmp;
	}

	for (int i = 1; i < n - 1; ++i){
		if(a[i - 1] % 2 == 1 && a[i] % 2  == 0 && a[i + 1] % 2 == 1){
			ans += (a[i - 1] + a[i] + a[i + 1]) / 2;
			a[i - 1] = a[i] = a[i + 1] = 0;
		}
	}

	for (int i = 0; i < n; ++i){
		ans += a[i] / 2;
		a[i] = a[i] % 2;
	}
	
	for (ll i = 1; i < n - 1; ++i){
		if(a[i - 1] == 1 && a[i] == 1){
			ans++; a[i - 1] = 0; a[i] = 0;
		}
		if(a[i] == 1 && a[i + 1] == 1){
			ans++; a[i] = 0; a[i + 1] = 0;
		}
	}
	printf("%lld\n", ans);

	return 0;
}