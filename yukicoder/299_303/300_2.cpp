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
typedef long long ll;
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

int main(void){
    ll x, y = 1;
    cin >> x;
    for(ll i = 2; i * i <= x; ++i){
        ll cnt = 0;
        while(x % i == 0){
            x /= i;
            cnt++;
        }
        if (cnt % 2 != 0) y *= i;
    }
    if(x > 1) y *= x;
    printf("%lld\n", y);

    return 0;
}