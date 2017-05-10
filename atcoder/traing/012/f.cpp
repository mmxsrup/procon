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

template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first1 ,
        BidirectionalIterator last1 ,
        BidirectionalIterator first2 ,
        BidirectionalIterator last2 )
{
    if (( first1 == last1 ) || ( first2 == last2 )) {
        return false ;
    }
    BidirectionalIterator m1 = last1 ;
    BidirectionalIterator m2 = last2 ; --m2;
    while (--m1 != first1 && !(* m1 < *m2 )){
    }
    bool result = (m1 == first1 ) && !(* first1 < *m2 );
    if (! result ) {
        while ( first2 != m2 && !(* m1 < * first2 )) {
            ++ first2 ;
        }
        first1 = m1;
        std :: iter_swap (first1 , first2 );
        ++ first1 ;
        ++ first2 ;
    }
    if (( first1 != last1 ) && ( first2 != last2 )) {
        m1 = last1 ; m2 = first2 ;
        while (( m1 != first1 ) && (m2 != last2 )) {
            std :: iter_swap (--m1 , m2 );
            ++ m2;
        }
        std :: reverse (first1 , m1 );
        std :: reverse (first1 , last1 );
        std :: reverse (m2 , last2 );
        std :: reverse (first2 , last2 );
    }
    return ! result ;
}
 
template < class BidirectionalIterator >
bool next_combination ( BidirectionalIterator first ,
        BidirectionalIterator middle ,
        BidirectionalIterator last )
{
    return next_combination (first , middle , middle , last );
}

int N, M, P, Q, R;
int x[400], y[400], z[400];
int memo[20][20];
int main(void){
	cin >> N >> M >> P >> Q >> R;
	rep(i, R) cin >> x[i] >> y[i] >> z[i];
	rep(i, R) memo[x[i] - 1][y[i] - 1] = z[i];
	vector<int> v;
	rep(i, N) v.pb(i);
	int ans = 0;
	do{
		vector<int> d(M, 0);
		rep(i, P){
			rep(j, M){
				d[j] += memo[v[i]][j];
			}
		}
		sort(all(d)); reverse(all(d));
		int tmp = 0;
		rep(i, Q)tmp += d[i];
		chmax(ans, tmp);
	}while(next_combination(v.begin(), v.begin() + P, v.end()));
	printf("%d\n", ans);
	return 0;
}