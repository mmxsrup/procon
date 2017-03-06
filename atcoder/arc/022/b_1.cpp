/*
尺取り法
頻度を計算して、２つ以上含まれる数字がないかを調べる
1部TLE
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;
 
#define COCOA 100000
 
int main()
{
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i]; v[i]--;
    }
    int cnt[COCOA] = {};
    int l = 0, res = 0;
    for (int r = 0; r < N; r++) {
        cnt[v[r]]++;
        while (cnt[v[r]] > 1) {
            cnt[v[l]]--;
            l++;
        }
        
        res = max(res, r - l + 1);
    }
    cout << res << endl;
    return 0;
}