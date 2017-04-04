#include "bits/stdc++.h"
using namespace std;
 
//#define int long long
#define DBG 1
#define dump(o) if(DBG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DBG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define each(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define all(c) c.begin(),c.end()
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);
 
bool f(string s) {
    if (s == "ABC")return true;
    if (s.size() <= 3)return false;
    string A = "", B = "", C = "";
    int a = 0, b = 0, c = 0;
    string t = s + "$$";
    cout << "s " << s << endl;
    rep(i, 0, s.size()) {
        if (t[i] == 'A'&&t[i + 1] == 'B'&&t[i + 2] == 'C') {
            A += "A";
            B += "B";
            C += "C";
            i += 2;
        }
        else {
            A += t[i];
            B += t[i];
            C += t[i];
            if (t[i] == 'A')a++;
            else if (t[i] == 'B')b++;
            else if (t[i] == 'C')c++;
        }
    }
    bool ret = false;
    if (s == A&&s == B&&s == C)return false;
    cout << A << endl;
    if (a == 0)ret |= f(A);
    cout << B << endl;
    if (b == 0)ret |= f(B);
    cout << C << endl;
    if (c == 0)ret |= f(C);
    return ret;
}
 
signed main() {
    string S; cin >> S;
    if (f(S))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}