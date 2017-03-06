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

	double a, b;
	cin >> a >> b;

	double tmp_a, tmp_b;

	reps(i, 1, 1000){
		//合計値を大きくしていく
		double sum = i;
		rep(j, sum + 1){
			tmp_a = sum - j;
			tmp_b = j;
			if (round((100.0 * tmp_a) / sum) == a && round((100.0 * tmp_b) / sum) == b){
				printf("%d\n", (int)sum);
				return 0;
			}
		}
	}

	return 0;
}