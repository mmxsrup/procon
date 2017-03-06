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

	for (ll i = 3; i * i <= n; ++i){ //i <= nでやる必要なない　繰り返して試しているだけ　ex21 3 * 7 = 21   7 * 3 = 21 
		if (n % i == 0){
			printf("%lld\n", i);
			return 0;
		}
	}

	//約数が見つからなかった時
	if (n % 2 == 0 && n > 4)
	{
		printf("%lld\n", n / 2);
	}else{
		printf("%lld\n", n);//primenなど
	}

	return 0;
}