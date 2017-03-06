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
	ll a, b, k, l;
	cin >> a >> b >> k >> l;

	ll settt = k / l;
	ll aaaa = k % l;

	ll ans1 = a * k;
	ll ans2, ans3;
	if(settt * l + aaaa >= k) ans2 = settt * b + aaaa * a;
	else ans2 = 1000000000000000;

	if((settt + 1) * l >= k) ans3 = (settt + 1) * b;
	else ans3 = 1000000000000000;


	ll ans = min(ans1, min(ans2, ans3));

	printf("%lld\n", ans);

	return 0;
}