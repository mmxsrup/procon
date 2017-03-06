// 逆再生問題?
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

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	int h, w;
	scanf("%d %d", &h, &w);
	int n;
	scanf("%d", &n);

	vector<char> s(n);
	vector<int> k(n);

	rep(i, n){
		cin >> s[i] >> k[i];
	}

	reverse(all(s));
	reverse(all(k));

	int nx = 0, ny = 0;
	rep(i, n){
		if (s[i] == 'R'){
			if (k[i] == ny){
				if (nx == 0)
					nx = w - 1;
				else
					nx--;
			}
		}else{
			if (k[i] == nx){
				if (ny == 0)
					ny = h - 1;
				else
					ny--;
			}
		}
	}

	if (nx % 2 == 0 && ny % 2 == 0)
		printf("white\n");
	else if(nx % 2 == 0 && ny % 2 == 1)
		printf("black\n");
	else if(nx % 2 == 1 && ny % 2 == 0)
		printf("black\n");
	else
		printf("white\n");

	return 0;
}





































