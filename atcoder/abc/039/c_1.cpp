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
	string s;
	cin >> s; 
	string memo = "WBWBWWBWBWBWWBWBWWBWWBWBWWBWBWBWWBWBWWBWWBWBWWBWBWBWWBWBWWBWWBWBWWBWBWBWWBWBWWBW";
	rep(i, 20){
		reps(j, i, i + 20){
			if(memo[j] != s[j]) break;
			if(j == i + 19){
				if (i % 7 == 0) printf("Do\n");
				else if (i % 7 == 1) printf("Re\n");
				else if (i % 7 == 2) printf("Mi\n");
				else if (i % 7 == 3) printf("Fa\n");
				else if (i % 7 == 4) printf("So\n");
				else if (i % 7 == 5) printf("La\n");
				else if (i % 7 == 6) printf("Si\n");
				return 0;
			}
		}
	}
}