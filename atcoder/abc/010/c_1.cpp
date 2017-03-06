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


//pow sqrtの実験
int main(void){
	double a = 4;
	double b = 25;

	double ans40 = pow(4, 1/2);
	double ans41 = sqrt(4);
	double ans42 = pow(4, 0.5);
	double ans250 = pow(25, 1 / 2);
	double ans251 = sqrt(25);
	double ans252 = pow(25, 0.5);

	printf("%f\n", ans40);
	printf("%f\n", ans41);
	printf("%f\n", ans42);
	printf("%f\n", ans250);
	printf("%f\n", ans251);
	printf("%f\n", ans252);
	
	return 0;
}