#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;

int main(void){
	int x, y, x2, y2;
	cin >> x >> y >> x2 >> y2;
	int ans = max(x, y);
	//x >= 0 y >= 0
	if(x == y && x2 == y2 && x2 <= x && y2 <= y){
		printf("%d\n", ans + 1);
	}else{
		printf("%d\n", ans);
	}
	return 0;
}