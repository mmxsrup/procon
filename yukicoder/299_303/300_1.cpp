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
    ll y = 1;
    //ll z;
    cin >> x;

    for (ll i = 2; i * i <= x; ++i){
        ll cnt = 0;
        while(x % i == 0){
            //割り切れるまで割っていく
            x /= i;
            cnt++;
        }

        if (cnt % 2 != 0){//因数が奇数個しかない時
            y *= i; //足りない因数をyに持って行く
            //printf("%lld %lld %lld\n", i, cnt, x);
        }
    }


    if(x > 1)
        y *= x;
    /*もともとのxの因数の中で２つ持つ可能性のある因数の最大値は√x　であるので、
    調べるのはi * i <= xまででよく それまでに割り切られなかったもので最後まで残っている因数は
    もともとのx自体で因数を２つ以上持つことはないので、その分は自動的にyに入れてあげればいい
    */

    printf("%lld\n", y);

    return 0;
}