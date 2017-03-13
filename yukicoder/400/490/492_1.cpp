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
const ll INF = 1e9;
const ll INFF = 1e18;

typedef vector<long long> vec;
typedef vector<vec> mat;
mat mul(mat &A,mat &B){ // A * B の計算
	mat C(A.size(), vec(B[0].size()));
	for(int i = 0; i < A.size(); i++){
		for(int k = 0;k < B.size(); k++){
			for(int j = 0; j < B[0].size(); j++){
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % (ll)MOD; // mod
			}
		}
	}
	return C;
}
mat pow(mat A, long long n){ // A^n の計算
	mat B(A.size(), vec(A.size()));
	for(int i = 0; i < A.size(); i++){
		B[i][i] = 1;
	}
	while(n > 0){
		if(n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}


int main(void){
	ll n; cin >> n;
	mat A(2, vec(2));
	A[0][0] = 100, A[0][1]  = 1;
	A[1][0] = 0,	A[1][1] = 1;
	auto ret = pow(A, n - 1);
	ll an = (ret[0][0] + ret[0][1]) % MOD;
	printf("%lld\n", an);

	int m = n % 11;
	ll ans = 0;
	rep(i, m){
		ans = ans * 100 + 1;
	}
	printf("%lld\n", ans);
	return 0;
}