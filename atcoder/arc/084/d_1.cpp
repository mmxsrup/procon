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

set<int> se[60];
vector<ll> v[60];

int main(void) {
	v[1] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000, 1000000000000000000};
	v[2] = {2, 11, 20, 101, 110, 200, 1001, 1010, 1100, 2000, 10001, 10010, 10100, 11000, 20000, 100001, 100010, 100100, 101000, 110000, 200000, 1000001, 1000010, 1000100, 1001000, 1010000, 1100000, 2000000, 10000001, 10000010, 10000100, 10001000, 10010000, 10100000};
	v[3] = {3, 12, 21, 30, 102, 111, 120, 201, 210, 300, 1002, 1011, 1020, 1101, 1110, 1200, 2001, 2010, 2100, 3000, 10002, 10011, 10020, 10101, 10110, 10200, 11001, 11010, 11100, 12000, 20001, 20010, 20100, 21000, 30000, 100002, 100011, 100020, 100101};
	v[4] = {4, 13, 22, 31, 40, 103, 112, 121, 130, 202, 211, 220, 301, 310, 400, 1003, 1012, 1021, 1030, 1102, 1111, 1120, 1201, 1210, 1300, 2002, 2011, 2020, 2101, 2110, 2200, 3001, 3010, 3100, 4000, 10003, 10012, 10021, 10030, 10102, 10111, 10120, 10201, 10210};
	v[5] = {5, 14, 23, 32, 41, 50, 104, 113, 122, 131, 140, 203, 212, 221, 230, 302, 311, 320, 401, 410, 500, 1004, 1013, 1022, 1031, 1040, 1103, 1112, 1121, 1130, 1202, 1211, 1220, 1301, 1310, 1400, 2003, 2012, 2021, 2030, 2102, 2111, 2120, 2201, 2210, 2300, 3002};
	// for(auto u : v[1]) cout << u << endl;
	return 0;
}