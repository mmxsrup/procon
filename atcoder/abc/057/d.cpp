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
const ll MOD = 1e9 + 9;
const int INF = 1e9;
const ll INFF = 1e18;
 
const int MAX_N = 60;
ll com[MAX_N][MAX_N];
void combination(void){ //com[i][j] := iCj
	com[0][0] = 1;
	for (int i = 1; i <= MAX_N - 1; ++i){
		for (int j = 0; j <= i; ++j){
			//パスカルの３角形
			if(j == 0) com[i][j] = com[i - 1][j];
			else com[i][j] = (com[i - 1][j] + com[i - 1][j - 1]);
		}
	}
}

int N, A, B;
map<ll, int> ma;
int main(void){
	cin >> N >> A >> B;
	vector<ll> v(N);
	rep(i, N) cin >> v[i];
	rep(i, N){
		ma[v[i]]++;
	}
	sort(all(v));
	reverse(all(v));
	long double sum = 0;
	int cnt = 0;
	rep(i, A){
		if(i == 0) cnt++;
		else{
			if(v[i - 1] == v[i])cnt++;
			else{
				cnt = 1;
			}
		}
		sum += v[i];
	}
	long double tsum = sum;
	int cntr = cnt;
	reps(i, A, B){
		ll tmp = sum + v[i];
		if(tmp * A == tsum * (i + 1)){
			cntr++, sum = tmp;
		}
		else break;
	}
	ll num = ma[v[A - 1]];
	ll ans = 0;
	combination();
	for (int i = cnt; i <= cntr; ++i){ // num C i
		// if(num < i) break;
		ans += com[num][i];
	}
	printf("%.7Lf\n", tsum / (double)A);
	// cout << (long double)tsum / (long double)A << endl;
	printf("%lld\n", ans);
	return 0;
}
