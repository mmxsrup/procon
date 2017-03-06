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


class primelib{
public:
	vector<int> prime; //prime[i] := iが素数の場合には0, 以外のときはiを割りる最大の素数
	vector<int> memo; 
	primelib(int size):prime(size + 10, 0), memo(size + 10, 0){
		prime_factorization(size + 1);
	}
	//[left,right]までのlcmがmemo[x]:=xの次数 として表される
	void getlcm(int left, int right){
		// fill(memo.begin(), memo.end(), 0); //0で初期化
		for (int i = max(2, left); i <= right; ++i){
			map<int, int> degree; //<x, k> := x^k
			int tmp = i;
			while(prime[tmp]){
				degree[prime[tmp]]++;
				tmp /= prime[tmp]; //最大の素数で割る
			}
			degree[tmp]++; //残った素数をカウント
			//memo[x] := [left, right]までを素因数分解した最大のxの次数を更新
			for(auto u : degree){
				memo[u.first] = max(memo[u.first], u.second);
			}
		}
	}
private:
	//prime[i] := iが素数の場合には0, 以外のときはiを割りる最大の素数
	//これを使えばO(logn)で素因数分解可能
	void prime_factorization(int n){
    	for (int i = 2; i <= n; i++) {
    		if (prime[i] == 0) {
        		for (int j = 2; j * i <= n; j++) {
            		prime[i * j] = i;
        		}
    		}
    	}
    }
};

class MissingLCM
{
public:
	int getMin(int N){
		int ans;
		primelib pba(2 * N), pbb(2 * N);
		for (int i = N; i >= 1; --i){
			if(pba.prime[i] == 0){
				ans = i; break;
			}
		}
		//答えが[2 * ans, 2*N]の中
		pba.getlcm(N + 1, 2 * ans); pbb.getlcm(1, 2 * ans);
		int ret;
		for (int i = 2 * ans; i <= 2 * N; ++i){
			if(pba.memo == pbb.memo){//lcmが一致しているか
				ret = i;
				break;
			}
			//i+1を付け足す
			pba.getlcm(i + 1, i + 1); pbb.getlcm(i + 1, i + 1);
		}
		return ret;
	}
};

/* TLE */
int main(void){
	MissingLCM lc;
	auto ret = lc.getMin(279841);
	printf("%d\n", ret);//559682
	return 0;
}