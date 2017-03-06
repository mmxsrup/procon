//半分全列挙
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
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)

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

int z[18][18];
int n, m, p, q, r;

int main(void){
	rep(i, 18)rep(j, 18) z[i][j] = 0;//初期化
	cin >> n>> m >> p >> q >> r;

	rep(i, r){
		int x, y; scanf("%d %d", &x, &y);
		//バケット(ビン)ソートしておくと番号の人を探す時に、ループを回さなくて済む
		scanf("%d", &z[x - 1][y - 1]);//z[女の番号][男の番号]
	}

	//女性は全てのコンビネーションを試すのでそのための配列を作る
	vector<int> woman(n);
	rep(i, n) woman[i] = i;//女子の番号を入れる

	int ans = 0;//答え
	do{//組み合わせを変えながら、女子を先頭から、p人ずつ選んでいく
		//man[i]には女性をp人選んだ時に、i番目の男によってどれだけ幸福度がもたらされるかが入っている
		vector<int> man(m, 0);//各男子による、幸福度の増加分を入れる配列
		rep(i, p){
			rep(j, m){
				//男子は全探索
				man[j] += z[woman[i]][j];
			}
		}
		//大きい順に並べる
		sort(all(man));
		reverse(all(man));

		int sum = 0;
		//貧欲てきに、幸福度が大きい男子から順に、良い男子をq人選ぶ
		rep(i, q){
			sum += man[i];
		}
		ans = max(ans, sum);

	}while(next_combination(woman.begin(), woman.begin() + p, woman.end()));
	printf("%d\n", ans);
	return 0;
}		