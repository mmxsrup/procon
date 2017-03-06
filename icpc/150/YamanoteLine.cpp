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
	int a, b, c;
	cin >> a >> b >> c;

	int v[100100];
	rep(i, 100000) v[i] = 0;

	for (int i = 0; i < 10000; i += (a + b)){
		reps(j, i, i + a) v[j] = 1;
	}

	int cnt = 0;
	for (int i = c - 1; i <= 10000; i += 60){
		cnt++;
		if(v[i] == 1){
			printf("%d\n", c + ((cnt - 1) * 60));
			return 0;
		}
	}

	printf("-1\n");
	return 0;
}
