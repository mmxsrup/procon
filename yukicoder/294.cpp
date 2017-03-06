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

ll a, b;
int ketaa = 0;
int ketab = 0;

void slove(void){
	string sa = to_string(a);
	string sb = to_string(b);
	rep(i, ketaa){
		if (sa[i] == '4' && sb[i] == '7'){
			printf("%lld\n", a);
			return;
		}else if(sa[i] == '7' && sb[i] == '4'){
			printf("%lld\n", b);
			return;
		}else if(sa[i] < sb[i]){
			printf("%lld\n", b);
			return;
		}else if(sa[i] > sb[i]){
			printf("%lld\n", a);
			return;
		}
	}
	return;
}
int main(void){
	scanf("%lld %lld", &a, &b);
	ll tmpa = a;
	ll tmpb = b;
	while(tmpa != 0){
		tmpa /= 10;
		ketaa++;
	}
	while(tmpb != 0){
		tmpb /= 10;
		ketab++;
	}
	if (ketaa > ketab){
		printf("%lld\n", a);
		return 0;
	}else if(ketab > ketaa){
		printf("%lld\n", b);
	}else{
		slove();
		return 0;
	}
	return 0;
	
}