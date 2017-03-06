#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
    int n, d;
    cin >> n >> d;
    int ans = 0;
    int sum = 0;

    rep(i, d){
        string s; cin >> s;
        rep(j, n){
            if(s[j] == '0'){
                sum++;
                //printf("%d %d %d\n", i, j, sum);
                break;
            }
            if(j == n - 1){
                ans = max(ans, sum);
                //printf("0nisuru\n");
                sum = 0;
            }
        }
    }
    ans = max(sum, ans);
    printf("%d\n", ans);
}