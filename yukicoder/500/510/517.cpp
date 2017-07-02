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

int main(void){
	int N, M;
	cin >> N;
	vector<string> A, B;
	rep(i, N){
		string d; cin >> d;
		A.pb(d);
	}
	cin >> M;
	rep(i, M){
		string d; cin >> d;
		B.pb(d);
	}
	
	rep(i, A.size())rep(j, A[i].size() - 1){
		rep(k, B.size() - 1)rep(l, B.size()){
			if(k == l) continue;
			if(B[k].back() == A[i][j] && B[l].front() == A[i][j + 1]){
				auto d = B[k] + B[l];
				B[k] = d;
				B.erase(B.begin() + l);
			}else if(B[l].back() == A[i][j] && B[k].front() == A[i][j + 1]){
				auto d = B[l] + B[k];
				B[k] = d;
				B.erase(B.begin() + l);
			}
		}
	}
	if(B.size() == 1){
		cout << B[0] << endl;
	}else{
		printf("-1\n");
	}
	return 0;
}