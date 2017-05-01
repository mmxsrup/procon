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

const double pi = 3.141592653589793;

ll R[1010], H[1010];
int K, N; 

void solve(void){
	cin >> N >> K;
	rep(i, N) cin >> R[i] >> H[i];
	
	//IDX半径は最大番号
	int IDX; ll mar = 0, mah = 0;
	rep(i, N){
		if((mar < R[i])){
			mar = R[i];
			mah = H[i];
			IDX = i;
		}else if(mar == R[i] && mah < H[i]){
			mar = R[i];
			mah = H[i];
			IDX = i;
		}
	}
	
	vector<pair<ll, int>> v;
	rep(i, N){
		ll d = 2 * R[i] * H[i];
		v.pb(mp(d, i));
	}

	sort(all(v)), reverse(all(v));
	double ans = 0;
	ll maR = 0; int idx; //Kこの中での半径最大の番号
	bool flag = false;
	rep(i, K){
		double d = pi * v[i].fi;
		ans += d;
		if(maR < R[v[i].se]){
			maR = R[v[i].se];
			idx = v[i].se;
		}
		if(v[i].se == IDX){
			flag = true;
		}
	}

	if(flag){ //Kこの中に半径最大も含まれる
		double men = pi * R[IDX] * R[IDX]; // idx -> IDX
		printf("%.9f\n", ans + men);
	}else{
		double men = pi * R[idx] * R[idx];
		vector<pair<ll, int>> vv;
		rep(i, N){
			if(i == IDX) continue;
			ll d = 2 * R[i] * H[i];
			vv.pb(mp(d, i));
		}
		sort(all(vv)), reverse(all(vv));
		double ans1 = 0;
		rep(i, K - 1){
			double d = pi * vv[i].fi;
			ans1 += d;
		}
		ans1 += 2.0 * pi * R[IDX] * H[IDX];
		double mendai = pi * R[IDX] * R[IDX];
		printf("%.9f\n", max(ans + men, ans1 + mendai));
	}
}

int main(void){
	int T; cin >> T;
	rep(i, T){
		printf("Case #%d: ", i + 1);
		solve();
	}
	return 0;
}