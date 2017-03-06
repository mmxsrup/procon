/*順列
next_permutationを使う
int main(void){
    vector<int> v(3);
    v[0] = 22;
    v[1] = 1;
    v[2] = 33;
    sort(v.begin(), v.end());
    rep(i, 3)
        printf("%d\n", v[i]);

    do{
        rep(i, 3)
            printf("%d\n", v[i]);
    }while(next_permutation(v.begin(), v.end()));
    return 0;
}
*/
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
#include <list>
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
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
    int N;
    scanf("%d", &N);
    vector<int> c(N);

    rep(i, N)
        scanf("%d", &c[i]);

    sort(all(c));

    int sum = 0;
    int p = 0;

    //これだと同じ数字が入っていた場合に対応できてない
    do{
        ///順列が変わるごとに新しいものを作る
        vector<int> flag(N, 0);//0は表、1は裏

        /*
        rep(i, N)
            printf("%d", c[i]);
        printf("\n");
        */
        
        rep(i, N - 1){
            int now = c[i];
            reps(j, i + 1, N){
                if (c[j] % now == 0){
                    if (flag[j] == 0)
                        flag[j] = 1;
                    else
                        flag[j] = 0;    
                }
            }
        }

        rep(i, N)
            if (flag[i] == 0)
                sum++;

        p++; //何通りの順列があるか
    }while(next_permutation(all(c)));

    /* 階乗を計算しなければいい
    ll p = 1; //階乗
    reps(i, 1, N + 1)
          p *= i;
    printf("sum%d\n", sum);
    */

    //printf("ans%d\n", sum);
    //printf("p%d\n", p);

    double ans = (double)sum / (double)p;

    printf("%.9f\n", ans);
    return 0;
}
