#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

//dp[i][j][k][l]
//整数pを考えた時に、i番目の桁まで考えて、j=1の時は考えている数がp未満であることが決定していて、j=0の時はp以下である。
//k=1の時はすでにi番目までに数字3を含んでいて、k=0の時は含まれていない。 lはi番目の桁まで考えた時のmod3の値
long long dp[30][2][2][3];

int main(void){
    int p; cin >> p;
    dp[0][0][0][0] = 1;
    rep(i, p + 1){
        rep(j, 2){

            int lim;
            if(j == 1) lim = 9;//i桁目までですでに未満が決まっていればi+1桁目の数字は何でもよい
            else if(j == 0 && i == 0) lim = 1;//未満が決まっていなくても１ケタ目には１を入れる場合がある
            else lim = 0;//未満が決まっていなければ0しか入れられない
            
            rep(k, 2){
                rep(l, 3){
                    rep(m, lim + 1){
                        dp[i + 1][j || m < lim][k || m == 3][(l + m) % 3] += dp[i][j][k][l];
                    }
                }
            }
        }
    }

    long long ans = 0;
    rep(j, 2) rep(k, 2) rep(l, 3){
        if(k == 1|| l == 0){//３が含まれているまたは３の倍数
            ans += dp[p + 1][j][k][l];
        }
    }
    cout << ans - 1 << endl;//0も含んで考えてしまっているので、   -1
    return 0;
}