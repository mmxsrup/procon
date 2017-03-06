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

int memo;
int ans[10] = {0};

int main(void){

    printf("0000000000\n");

    int num;
    string ss;
    cin >> num >> ss;    
    memo = num; 
    if (num == 10){
        return 0;
    }

    rep(i, 10){//どこの位置の数字を変えるか
        rep(j, 10){//変えている数字の番号

            if(i == 0)
                printf("%d000000000\n", j);
            else if (i == 1)
                printf("0%d00000000\n", j);
            else if (i == 2)
                printf("00%d0000000\n", j);
            else if (i == 3)
                printf("000%d000000\n", j);
            else if (i == 4)
                printf("0000%d00000\n", j);
            else if (i == 5)
                printf("00000%d0000\n", j);
            else if (i == 6)
                printf("000000%d000\n", j);
            else if (i == 7)
                printf("0000000%d00\n", j);
            else if (i == 8)
                printf("00000000%d0\n", j);
            else if (i == 9)
                printf("000000000%d\n", j);

            int n;
            string s;
            cin >> n >> s;	
            if (n == 10){
                return 0;
            }

            if (n > memo)
                ans[i] = j;
        }	
    }


    rep(i, 10){
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}