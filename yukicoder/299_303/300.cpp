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

int main(void){
    ll x;
    ll y;
    ll z;
    cin >> x;

    ll tmp = x;
    int keta = 0;
    while(tmp != 0){
        tmp /= 10;
        keta++;
    }

    ll a;
    if (keta == 1)
        a = 1;
    else
        a = 10 * (keta - 1);

    for (ll i = a; i < 1000000000; ++i)
    {
        //printf("%lld\n", i);
        z = i * i;
        if (z % x == 0){
            y = z / x;
            printf("%lld\n", y);
            return 0;
        }
    }

    return 0;
}