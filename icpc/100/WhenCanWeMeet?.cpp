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
	int n, q; //会員数　最低人数

	while(1){
		cin >> n >> q;
		if(n == 0) break;
		int date[100000] = {0};
		rep(i, n){
			int m; cin >> m;
			rep(j, m){
				int tmp;
				cin >> tmp;
				date[tmp]++;
			}
		}

		int max = 0;
		rep(i, 100000){
			if(date[max] < date[i]) max = i;
		}
		if(date[max] >= q) printf("%d\n", max);
		else printf("0\n");
	}
	return 0;
}