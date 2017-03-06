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

ll mergecount(vector<int> &a) {
  ll count = 0;
  int n = a.size();
  if (n > 1) {
    vector<int> b(a.begin(), a.begin() + n/2);
    vector<int> c(a.begin() + n/2, a.end());
    count += mergecount(b);
    count += mergecount(c);
    for (int i = 0, j = 0, k = 0; i < n; ++i)
      if (k == c.size())       a[i] = b[j++];
      else if (j == b.size())  a[i] = c[k++];
      else if (b[j] <= c[k])   a[i] = b[j++];
      else                   { a[i] = c[k++]; count += n/2 - j; }
  }
  return count;
}

int main(void){
	int n; cin >> n;
	vector<int> a(n);
	rep(i, n){
		cin >> a[i];
	}

	ll ans = 0; bool flag = true;
	while(flag){
		flag = false;
		for (int i = 0; i < n - 2; ++i){
			if(a[i] > a[i + 2]){
				swap(a[i], a[i + 2]);
				flag = true;
			}
		}
	}
	/*
	rep(i, n){
		printf("%d", a[i]);
	}
	printf("\n");
	*/
	/*
	flag = true;
	while(flag){
		flag = false;
		for (int i = 0; i < n - 1; ++i){
			if(a[i] > a[i + 1]){
				swap(a[i], a[i + 1]);
				ans++;
				flag = true;
			}
		}
	}
	*/
	printf("%lld\n", mergecount(a));
	return 0;
}