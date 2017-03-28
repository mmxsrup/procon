#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
typedef pair<int,int> pint;
typedef vector<pint> vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define chmax(a, b) a = (((a)<(b)) ? (b) : (a))
#define chmin(a, b) a = (((a)>(b)) ? (b) : (a))
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll INFF = 1e18;

string s;
int main(void){
	cin >> s;
	int a[5] = {0};
	for(auto u : s){
		if(u == 'y') a[0]++;
		else if(u == 'a') a[1]++;
		else if(u == 'h') a[2]++;
		else if(u == 'o') a[3]++;
	}
	if(a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 2){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}