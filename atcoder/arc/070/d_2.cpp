
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

int N, K;
int a[5010];

bool dpl[5010][5010]; //dpl[i][j] := 1からi番目までを考えて,合計がjの時があるなら1
bool dpr[5010][5010]; //dpr[i][j] := Nからi番目までを考えて,合計がjの時があるなら1

int main(void){
	cin >> N >> K;
	rep(i, N) cin >> a[i];

	dpl[0][0] = 1;
	rep(i, N)rep(j, K + 1){
		if(dpl[i][j] == 0) continue;
		dpl[i + 1][j] = 1;
		if(j + a[i] > K) continue;
		dpl[i + 1][j + a[i]] = 1;
	}

	dpr[N + 1][0] = 1;
	for(int i = N; i >= 1; i--)rep(j, K + 1){
		if(dpr[i][j] == 0) continue;
		dpr[i - 1][j] = 1;
		if(j + a[i - 1] > K) continue;
		dpr[i - 1][j + a[i - 1]] = 1;
	}

	int ans = 0;
	reps(i, 1, N + 1){ //i番目を含まない部分集合
		vector<int> vl, vr;
		reps(j, 1, K + 1)if(dpl[i - 1][j]) vl.pb(j);
		reps(j, 1, K + 1)if(dpr[i + 1][j]) vr.pb(j);
		//[K-a[i], K)が存在するかを探す
		bool flag = true;
	}
	return 0;
}