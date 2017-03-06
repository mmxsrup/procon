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

int n;

bool slove (int a, int b, int c, vint array){
	int cnt = 0;
	k_array.erase(array.begin() + a, array.begin() + b, array.begin() + c);
	rep(i, n - 3)
	


}


int main(void){
	cin >> n;
	vint k_array(n);
	rep(i, n)
		cin >> k_array[i];

	rep(i, n - 2){
		reps(j, i, n - 1){
			reps(k, j, n){
				if (slove(i, j, k)){
					printf("%d %d %d\n", i, j, k, k_array);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}