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


int H, W;
ll A, B;
string m[210];
int cnt[210][210];
int memo[210][210];

int main(void) {
	cin >> H >> W >> A >> B;
	rep(i, H) cin >> m[i];


	ll cA = 0, cB = 0;
	rep(i, H / 2)rep(j, W) {
		if(m[i][j] != m[H - i - 1][j]) {
			cA++;
			if(m[i][j] == 'S') cnt[i][j]++;
			else cnt[H - i - 1][j]++;
		}
	}
	rep(i, H)rep(j, W / 2) {
		if(m[i][j] != m[i][W - j - 1]) {
			cB++;
			if(m[i][j] == 'S') cnt[i][j]++;
			else cnt[i][W - j - 1]++;
		}
	}

	rep(i, H)rep(j, W) if(cnt[i][j] == 2) m[i][j] = '.';
	/*
	printf("\n");
	rep(i, H){
		rep(j, W) printf("%d ", cnt[i][j]);
		printf("\n");
	}
	printf("\n");
	rep(i, H) cout << m[i] << endl;
	*/
	ll sum = 0;
	rep(i, H)rep(j, W) if(m[i][j] == 'S') sum++;

	ll ncA = 0, ncB = 0;
	rep(i, H / 2)rep(j, W) {
		if(m[i][j] != m[H - i - 1][j]) {
			ncA++;
			if(m[i][j] == 'S') memo[i][j]++;
			else memo[H - i - 1][j]++;
		}
	}
	rep(i, H)rep(j, W / 2) {
		if(m[i][j] != m[i][W - j - 1]) {
			ncB++;
			if(m[i][j] == 'S') memo[i][j]++;
			else memo[i][W - j - 1]++;
		}
	}


	// printf("ncA %lld ncB %lld sum %lld\n", ncA, ncB, sum);
	ll ans = A + B;
	ll nokori = 0;
	rep(i, H)rep(j, W) if(memo[i][j] == 1) nokori++;

	if(ncA == 0 && ncB == 0) { // xy対象
		ll ma = max(A, B);
		ll one = ma + A + B;
		ll tans = one * (sum / 4);
		chmax(ans, tans);
	}else if(ncA == 0) { // y 対象
		ll ansA = 0;
		ansA += (nokori/2) * A;
		ll ato = sum - nokori;
		if(ato > 0) {
			ansA += B;
			ll ma = max(A, B);
			ll one = ma + A + B;
			ansA += one * (ato / 4);
		}else{
			ansA += B;
		}
		chmax(ans, ansA);
	}else if(ncB == 0) { // x
		ll ansB = 0;
		ansB += (nokori/2) * B;
		ll ato = sum - nokori;
		if(ato > 0) {
			ansB += A;
			ll ma = max(A, B);
			ll one = ma + A + B;
			ansB += one * (ato / 4);
		}else{
			ansB += A;
		}
		chmax(ans, ansB);
	}else{
		ll ansA = A + B;
		ll nokoria = sum - ncA;
		ansA += (nokoria / 2) * A;
		chmax(ans, ansA);
		ll ansB = A + B;
		ll nokorib = sum - ncB;
		ansB += (nokorib / 2) * B;
		chmax(ans, ansB);
	}

	printf("%lld\n", ans);
	return 0;
}