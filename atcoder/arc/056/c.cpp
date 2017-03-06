#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<pint> vpint;
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)

//コンビネーションライブラリ
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
 
int w[18][18];
int n, k;
 
int main(void){
	rep(i, 18)rep(j, 18) w[i][j] = 0;//初期化
	cin >> n>> k;
 	rep(i, n) rep(j, n) scanf("%d", &w[i][j]);

 	reps(i, 1, n + 1){//1からnのグループに分ける
 		

 	}


	return 0;
}		