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

int main(void){
	int txa, tya, txb, tyb, t, v;
	int n;
	cin >> txa >> tya >> txb >> tyb >> t >> v;
	cin >> n;

	int lim = t * v;

	rep(i, n){
		double x, y;
		cin >> x >> y;
		double dis1 = ((x - txa) * (x - txa)) + ((y - tya) * (y - tya));
		double dis2 = ((txb - x) * (txb - x)) + ((tyb - y) * (tyb - y));
		//printf("\n");
		//printf("%f %f\n", dis1, dis2);
		//double distance = sqrt(dis1) + sqrt(dis2);
		double distance = pow(dis1, 0.5) + pow(dis2, 0.5);
		//printf("%f\n", distance);
		if(distance <= lim){
			printf("YES\n"); 
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}