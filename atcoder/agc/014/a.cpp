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

ll A, B, C;

int main(void){
	cin >> A >> B >> C;
	int cnt = 0;
	while(1){
		if(A % 2 || B % 2 || C % 2)break;
		if(cnt >= 1000000){
			printf("-1\n");
			return 0;
		}
		ll tA = B / 2 + C / 2;
		ll tB = A / 2 + C / 2;
		ll tC = A / 2 + B / 2;
		A = tA;
		B = tB;
		C = tC;
		cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}