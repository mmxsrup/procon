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
	double R0, W0, C, R;
	while(1){
		cin >> R0 >> W0 >> C >> R;
		if(R0 == 0) break;

		double tmp;
		rep(x, 100000000){
			tmp = (R0 + (x * R)) / C - W0;
			if(tmp >= 0){
				printf("%d\n", x);
				break;
			}
		}
	}

	return 0;
}