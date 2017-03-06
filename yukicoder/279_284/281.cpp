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

int d;

int hantei(int l, int m, int r, int cnt){
	if(l < m && m > r){
		//真ん中最大
		printf("1dayo%d l %d m %d r %d\n", cnt, l, m, r);
		return cnt;
	}
	if(l > m && m < r){
		//真ん中最小
		printf("2dayo%d l %d m %d r %d\n", cnt, l, m, r);
		return cnt;
	}

	//再帰関数
	if(l >= m && m >= r){
		printf("3dayo%d l %d m %d r %d\n", cnt, l, m, r);
		hantei(max(l - d, 0), m, r, cnt++);
		hantei(l, max(m - d, 0), r, cnt++);
	}else if(l <= m && m <= r){
		printf("4dayo%d l %d m %d r %d\n", cnt, l, m, r);
		hantei(l, m, max(r - d, 0), cnt++);
		hantei(l, max(m - d, 0), r, cnt++);
	}
}

int main(void){
	cin >> d;
	int h1, h2, h3;
	cin >> h1 >> h2 >> h3;

	hantei(h1, h2, h3, 0);
	
	return 0;
}