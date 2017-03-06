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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

ll slove(ll x){
	ll wa = 0;
	reps(i, 1, x + 1){
		wa += i;
	}
	return wa;
}

int main(void){
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n)
		cin >> a[i];

	ll sum = 0;
	ll cnt = 1;
	rep(i, n - 1){
		if (a[i] < a[i + 1]){
			cnt++;
			if (i == n - 2)
				sum += slove(cnt);
		
		}else if(a[i] >= a[i + 1] || i == n - 2){
			sum += slove(cnt);
			cnt = 1;
		}
	}

	if (a[n - 2] >= a[n - 1])
	{
		sum++;
	}

	printf("%lld\n", sum);
	return 0;
}

























