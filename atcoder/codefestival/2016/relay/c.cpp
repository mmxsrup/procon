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

int N;
int A[2000000];
int main(void){
	cin >> N;
	reps(i, pow(2, N), pow(2, N) * 2) cin >> A[i];
	int size = pow(2, N - 1);
	while(size >= 1){
		for (int i = size; i < size * 2; i++){
			if(A[i * 2] > A[i * 2 + 1]) A[i] = A[i * 2] - A[i * 2 + 1];
			else if(A[i * 2] == A[i * 2 + 1]) A[i] = A[i * 2];
			else A[i] = A[i * 2 + 1] - A[i * 2];
			// printf("%d %d %d\n", A[i], A[i * 2], A[i * 2 + 1]);
		}
		size >>= 1;
	}
	printf("%d\n", A[1]);
	return 0;
}