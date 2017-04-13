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

int a1, a2;
int b1, b2;
int c;
int main(void){
	cin >> a1 >> a2;
	set<int> sa;
	sa.insert(a1), sa.insert(a2);
	cin >> b1 >> b2;
	set<int> sb;
	sb.insert(b1), sb.insert(b2);
	set<int> ss;
	ss.insert(a1), ss.insert(a2), ss.insert(b1), ss.insert(b2);
	cin >> c;

	if(sa.count(c) && sb.count(c)){
		printf("%d\n", ss.size());
		for(auto u : ss){
			printf("%d\n", u);
		}
	}else if(sa.count(c)){
		printf("%d\n", sb.size());
		for(auto u : sb){
			printf("%d\n", u);
		}
	}else{
		printf("%d\n", sa.size());
		for(auto u : sa){
			printf("%d\n", u);
		}
	}
	return 0;
}