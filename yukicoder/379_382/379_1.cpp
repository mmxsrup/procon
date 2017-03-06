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
    ll  n, g, v; cin >> n >> g >> v;
    int maisuu = n / 5;
    ll sum = g * maisuu;
    double ans = (double)sum / (double)v;
    printf("%.14f\n", ans);
    return 0;
}