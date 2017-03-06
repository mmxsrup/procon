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
	int n, t;
	cin >> n >> t;
	ll sum = 0;
	vint sa(n);

	rep(i, n){
		int a, b;
		scanf("%d %d", &a, &b);
		sum += a;
		sa[i] = a - b;
	}
	sort(all(sa));
	reverse(all(sa));

	int time = sum  - t;
	int cnt = 0;
	while(time > 0){
		time -= sa[cnt];
		cnt++;
		if (cnt == n && time > 0){
			printf("-1\n");
			return 0;
		}
	}

	printf("%d\n", cnt);
	return 0;
}