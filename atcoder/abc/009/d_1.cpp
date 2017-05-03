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

// N*N行列Aを作りたい場合 mat A(N, vec(N));
typedef vector<long long> vec;
typedef vector<vec> mat;
// +->and *->xor
mat mul(mat &A,mat &B){ // A * B の計算
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i++){
        for(int k = 0; k < B.size(); k++){
            for(int j = 0; j < B[0].size(); j++){
                C[i][j] = C[i][j] ^ (A[i][k] & B[k][j]); //演算子置き換え
            }
        }
    }
    return C;
}
mat pow(mat A, long long n){ // A^n の計算
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i++){
        B[i][i] = 0xffffffffffffffff; //単位元 全ての桁に1が必要
    }
    while(n > 0){
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(void){
    int K, M;
    long long A[110], C[110];
    cin >> K >> M;
    rep(i, K) cin >> A[i];
    rep(i, K) cin >> C[i];
    if(M <= K) {
        cout << A[M - 1] << endl;
        return 0;
    }
    mat B(K, vec(K, 0));
    rep(i, K) B[0][i] = C[i];
    rep(i, K - 1) B[i + 1][i] = 0xffffffffffffffff; //単位元 全ての桁に1が必要
    auto Bn = pow(B, M - K);

    mat A0(K, vec(1));
    rep(i, K) A0[i][0] = A[K - 1 - i];
    auto ret = mul(Bn, A0);
    printf("%lld\n", ret[0][0]);
    return 0;
}

