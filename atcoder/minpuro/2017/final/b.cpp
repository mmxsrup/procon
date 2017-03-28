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

int N, M, K;
int A[100010], B[100010];
bool slv(int m){
	// printf("m; %d\n", m);
	int cnt = 0; //bool flag = true;
	int idxB = 0;
	rep(i, N){
		int off = 0;
		while((idxB + off) < M && abs(A[i] - B[idxB+ off]) > m){
			off++;
		}
		if(idxB + off >= M) continue;
		// printf("%d %d\n", i, idxB + off);
		if(abs(A[i] - B[idxB + off]) <= m){
			cnt++;
			idxB += off;
		}
		idxB++;
		if(idxB >= M) break;
	}
	// printf("cnt %d\n", cnt);
	if(cnt >= K) return true;
	else return false;
}

int main(void){
	cin >> N >> M >> K;
	rep(i, N) cin >> A[i];
	rep(i, M) cin >> B[i];
	sort(A, A + N); sort(B, B + M);
	int l = 0, r = INF + 1;
	while(r - l > 1){
		int m = (l + r) / 2;
		if(slv(m)) r = m;
		else l = m;
	}
	printf("%d\n", l + 1);
	return 0;
}