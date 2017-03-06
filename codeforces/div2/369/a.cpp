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
	int n; cin >> n;
	vector<string> s(n);
	rep(i, n){
		cin >> s[i];
	}
	//OO|OX
	rep(i, n){
		if(s[i][0] == 'O' && s[i][1] == 'O'){
			s[i][0] = '+';
			s[i][1] = '+';
			printf("YES\n");
			break;
		}
		if(s[i][3] == 'O' && s[i][4] == 'O'){
			s[i][3] = '+';
			s[i][4] = '+';
			printf("YES\n");
			break;
		}
		if(i == n - 1){
			printf("NO\n");
			return 0;
		}
	}

	rep(i, n){
		cout << s[i] << endl;
	}
	return 0;
}