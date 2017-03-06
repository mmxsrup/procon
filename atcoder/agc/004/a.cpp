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
	ll a, b, c; cin >> a >> b >> c;
	if(a % 2 == 0 || b % 2 == 0 || c % 2 == 0){
		printf("0\n"); return 0;
	}else{
		ll mi = min(a, min(b, c));
		ll ma = max(a, max(b, c));
		ll mannnaka = a + b + c - mi - ma;
		printf("%lld\n", mi * mannnaka);
	}

	return 0;
}