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

int a[100010];
int main(void){
	int n; cin >> n;
	rep(i, n){
		cin >> a[i];
	}
	int ki = 0, gu = 0;
	rep(i, n){
		if(a[i] % 2 == 0){
			gu++;
		}else{
			ki++;
		}
	}
	if(gu % 2 == 0 && ki % 2 == 0){
		printf("YES\n");
	}else if(gu % 2 == 0 && ki % 2 == 1){
		printf("NO\n");
	}else if(gu % 2 == 1 && ki % 2 == 0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	return 0;
}