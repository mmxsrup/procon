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
	string s;
	cin >> s;

	int cnt = s.size();

	int min_cww = 1000000;
	rep(i, cnt){
		if (s[i] == 'c')
		{
			int cnt_w = 0;
			reps(j, i + 1, cnt){
				if(0 <= j && j <= cnt - 1){
					if (s[j] == 'w')
						cnt_w++;
					if (cnt_w == 2)
						min_cww = min(min_cww, j - i + 1);
				}
			}
		}
	}

	if (min_cww != 1000000)
		printf("%d\n", min_cww);
	else
		printf("-1\n");

	return 0;

}