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
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;


class Parser{
public:
    int expression(State &begin){
        int ret = term(begin);
        for(;;){
            if(*begin == '+'){
                begin++;
                ret += term(begin);
            }else if(*begin == '-'){
                begin++;
                ret -= term(begin);
            }else{
                break;
            }
        }
        return ret;
    }
    int term(State &begin){
        int ret = factor(begin);
        for(;;){
            if(*begin == '*'){
                begin++;
                ret *= factor(begin);
            }else if(*begin == '/'){
                begin++;
                ret /= factor(begin);
            }else{
                break;
            }
        }
        return ret;
    }
    int factor(State &begin){
        int ret;
        if(*begin == '('){
            begin++;//'('を無視
            ret = expression(begin);
            begin++;//')'を無視
        }else{
            ret = number(begin);
        }
        return ret;
    }
    int number(State &begin){
        int ret = 0;
        while(isdigit(*begin)){
            ret *= 10;
            ret += *begin - '0';
            begin++;
        }
        return ret;
    }
};
