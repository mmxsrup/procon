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
	int n, q;
	cin >> n;
	vector<ll> s(n);
	rep(i, n)
		cin >> s[i];
	cin >> q;
	vector<ll> t(q);
	rep(i, q)
		cin >> t[i];
	sort(all(s));
	sort(all(t));

	ll cnt = 0, ans = 0;
	rep(i, q){
		ll now = t[i];

		while(now > s[cnt] && cnt < n)
			cnt++;

		if (now == s[cnt] && cnt < n)
			ans++;

		cnt++;
	}

	printf("%lld\n", ans);
	return 0;

}