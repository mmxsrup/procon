//分割数が最も少ない軸は３条根n以下

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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){

	ll n;
	cin >> n;
	ll amax = n - 1;//スライス

	ll amin = amax;
	for (ll i = 1; i*i*i <= n; ++i){
		for (ll j = 1; j <= n / i; ++j){
			if (n % (i + j) == 0){
				ll k = n / (i + j);
	
				if (i * j * k == n) amin = min(amin, i + j + k - 3);
	
			}
		}
	}

	printf("%lld %lld\n", amin, amax);
}


















