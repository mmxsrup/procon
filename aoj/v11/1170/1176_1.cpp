#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=n-1;i>=(0);i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define eall(v) unique(all(v), v.end())
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;
 
int h, w, s;
int U[35][35];
int allsum = 0;
// dp[y1][x1][y2][x2] := 左上(y1, x1), 右下(y2, x2)の長方形を考えた時の, 
// グループの分け方の最大数, 最大の予備力
pair<int, int> dp[35][35][35][35];
 
// O(hw)
template <class T>
vector<vector<T>> Imos2D(const vector<vector<T>>& a) {
    int h = a.size(), w = a[0].size();
    vector<vector<T>> s(h + 1, vector<T>(w + 1, 0));
    for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) s[i + 1][j + 1] = a[i][j];
    for (int i = 0; i < h + 1; ++i) for (int j = 0; j < w; ++j) s[i][j + 1] += s[i][j];
    for (int i = 0; i < h; ++i) for (int j = 0; j < w + 1; ++j) s[i + 1][j] += s[i][j];
    return s;
}
// O(1)
template <class T>
int sum(const vector<vector<T>>& s, int i, int j, int h, int w) {
    return s[i + h][j + w] - s[i][j + w] + s[i][j] - s[i + h][j];
}
 
pair<int, int> dfs(int y1, int x1, int y2, int x2, auto imos) {
    if(dp[y1][x1][y2][x2] != make_pair(0, INF)) return dp[y1][x1][y2][x2];
     
    int yobi = s - (allsum - sum<int>(imos, y1, x1, y2 - y1 + 1, x2 - x1 + 1));
    // if(yobi < 0) return make_pair(0, INF);
    auto ret = make_pair(1, yobi);
 
    for (int i = x1; i < x2; ++i){
        if(s - (allsum - sum<int>(imos, y1, x1, y2 - y1 + 1, i - x1 + 1)) < 0) continue;
        if(s - (allsum - sum<int>(imos, y1, i + 1, y2 - y1 + 1, x2 - (i + 1) + 1)) < 0) continue;
        auto ret1 = dfs(y1, x1, y2, i, imos);
        auto ret2 = dfs(y1, i + 1, y2, x2, imos);
        chmax(ret, make_pair(ret1.fi + ret2.fi, min(ret1.se, ret2.se)));
    }
 
    for (int i = y1; i < y2; ++i){
        if(s - (allsum - sum<int>(imos, y1, x1, i - y1 + 1, x2 - x1 + 1)) < 0) continue;
        if(s - (allsum - sum<int>(imos, i + 1, x1, y2 - (i + 1) + 1, x2 - x1 + 1)) < 0) continue;
        auto ret1 = dfs(y1, x1, i, x2, imos);
        auto ret2 = dfs(i + 1, x1, y2, x2, imos);
        chmax(ret, make_pair(ret1.fi + ret2.fi, min(ret1.se, ret2.se)));
    }
    return dp[y1][x1][y2][x2] = ret;
}
 
int main(void) {
    while(1) {
        scanf("%d %d %d", &h, &w, &s);
         
        if(h == 0 && w == 0 && s == 0) break;
        rep(i, h)rep(j, w) scanf("%d", &U[i][j]);
        allsum = 0;
        rep(i, h)rep(j, w) allsum += U[i][j];
 
        vector<vector<int>> u(h);
        rep(i, h)rep(j, w) u[i].pb(U[i][j]);
        auto imos = Imos2D<int>(u);
        rep(i, 35)rep(j, 35)rep(k, 35)rep(l, 35) dp[i][j][k][l] = make_pair(0, INF);
 
        auto ans = dfs(0, 0, h - 1, w - 1, imos);
        printf("%d %d\n", ans.fi, ans.se);
    }
    return 0;
}