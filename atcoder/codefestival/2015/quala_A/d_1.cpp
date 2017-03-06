#include <iostream>
#include <algorithm>
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

int n, m;
int x[100000];


bool slove(int t){
	printf("tttt %d\n", t);
	int damel = 1;
	rep(i, m){
		int now = x[i];
		if(damel == now - 1) damel += t + 2;
		else id(damel = now) damel += t + 1
		else if(damel > now - 1) damel += t + 1;
		else{
			if(now - damel > double(t) / 2.0){
				printf("yee1\n");
				damel += (t - now + damel) / 2;
			}else{
				printf("ye\n");
				damel += t - 2 * (now - damel);
			}
			damel = max(damel, x[i] + 1);
		}
		printf("%d\n", damel);
	}
	if(damel > n) return true;
	return false;
}

int main(void){
	cin >> n >> m;
	rep(i, m) scanf("%d", &x[i]);

	rep(i, 101){
		if(slove(i) == true){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}