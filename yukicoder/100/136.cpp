#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

bool isprime[100010];//trueならiは素数
//エラトテネス
void eratos(int m){
    for (int i = 0; i <= m; ++i) isprime[i] = true;
    isprime[0] = isprime[1] = false;
    //iを残してiの倍数を消していく
    for (int i = 2; i <= m; ++i){
        if(isprime[i]){
            for (int j = 2 * i; j <= m; j += i){
                isprime[j] = false;
            }
        }
    }
    return;
}

int main(void){
    eratos(100010);
    int n, k; cin >> n >> k;
    if(isprime[n]){//prime : 1
        printf("1\n");
        return 0;
    }
    int ans = 0;
    for (int i = 2; i < n; ++i){
        int j = n - i;
        ans = max(ans, __gcd(i, j));
    }
    printf("%d\n", ans);
}