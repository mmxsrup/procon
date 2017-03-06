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

int num[10] = {0};

int main(void){
	int n;
	cin >> n;
	int purasu = 0, mainasu = 0;
	rep(i, n){
		char tmp[2];
		cin >> tmp;

		if (tmp[0] == '+')
			purasu++;
		else if(tmp[0] == '-')
			mainasu++;
		else if(tmp[0] == '0')
			num[0]++;
		else if(tmp[0] == '1')
			num[1]++;
		else if(tmp[0] == '2')
			num[2]++;
		else if(tmp[0] == '3')
			num[3]++;
		else if(tmp[0] == '4')
			num[4]++;
		else if(tmp[0] == '5')
			num[5]++;
		else if(tmp[0] == '6')
			num[6]++;
		else if(tmp[0] == '7')
			num[7]++;
		else if(tmp[0] == '8')
			num[8]++;
		else if(tmp[0] == '9')
			num[9]++;

		
		

	}

	//printf("%d %d %d\n", purasu, mainasu, num[0]);
	return 0;
}