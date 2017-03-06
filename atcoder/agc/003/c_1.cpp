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

ll mergecount(vector<ll> &a) {
  ll count = 0;
  ll n = a.size();
  if (n > 1) {
    vector<ll> b(a.begin(), a.begin() + n/2);
    vector<ll> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (ll i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

int main(void){
	ll n; cin >> n;
	vector<ll> tmp1, tmp2;
	vector<ll> a;
	rep(i, n){
		ll t; cin >> t;
		if(i % 2 == 0) tmp1.push_back(t);
		else tmp2.push_back(t);
	}
	sort(all(tmp1)); sort(all(tmp2));

	rep(i, n){
		if(i % 2 == 0) a.push_back(tmp1[i / 2]);
		else a.push_back(tmp2[i / 2]);
	}
	printf("%lld\n", mergecount(a));
	return 0;
}