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

int N, Q;
int A[100010], B[100010];
map<int, int> ps; // ps[i] := i番目の位置にあるコップの番号
int main(void){
	cin >> N >> Q;
	rep(i, Q) cin >> A[i] >> B[i];
	reps(i, 1, N + 1) ps[i] = i;
	set<int> ans;
	int d = 1; // コップ1の位置
	ans.insert(1), ans.insert(2);
	rep(i, Q){
		if(ps[A[i]] == 1) d = B[i];
		else if(ps[B[i]] == 1) d = A[i];
		swap(ps[A[i]], ps[B[i]]);
		
		if(d == 1) ans.insert(ps[2]);
		else if(d == N) ans.insert(ps[N - 1]);
		else ans.insert(ps[d - 1]), ans.insert(ps[d + 1]);
	}
	printf("%d\n", (int)ans.size());
	return 0;
}