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

int main(void){
    int n; scanf("%d", &n);
    string s; cin >> s;
    int a = s[0] - '0';
    if(a == 0) a = 11;
    int tmp = a;
    while(tmp > 1){
        tmp -= 3;
        reps(i, 1, n){
            if(s[i] != 0 && s[0] - '0' <= 3) break;
            if(s[i] != '0' && s[0] - '0' >= 4 && i == n -1){
                printf("YES\n");
                return 0;
            }
        }
    }
    tmp = a;
    while(tmp < 11){
        tmp += 3;
        reps(i, 1, n){
            if(s[i] != 7 && s[i])
        }
    }

	return 0;
}	