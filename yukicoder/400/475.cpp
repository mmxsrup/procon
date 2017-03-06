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

int n, s, writer_id;
ll a[798000];

int main(void){
	cin >> n >> s >> writer_id;
	rep(i, n) cin >> a[i];

	ll writer_score = a[writer_id] + s;
	int cnt = 0;
	rep(i, n){
		if(i == writer_id) continue;
		double t = 50 * s + (50 * s) / (0.8 + 0.2 * 1);
		if(t >= writer_score) cnt++;
	}
	printf("%.9f\n", );
	return 0;
}