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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
//int dx[4] = {1, 0, 0, -1};
//int dy[4] = {0, 1, -1, 0};

double ans(double cnt){
	double kakuritu = 1 / (cnt * 4);
	return kakuritu;
}

int main(void){
	ll n, d;
	ll x, y;//目標

	cin >> n >> d;
	cin >> x >> y;

	ll dx[4] = {d, 0, 0, -d};
	ll dy[4] = {0, d, -d, 0};

	queue <pair<ll, ll> > q;
	q.push(mp(0, 0));
	double cnt = 0;
	while(!q.empty() && cnt <= pow(4, n - 1) + 1){
		cnt++;
		//printf("cnt%f\n", cnt);
		pair<ll, ll> tmp = q.front();//first x  second y
		q.pop();

		rep(i, 4){
			ll nx = tmp.fi + dx[i];
			ll ny = tmp.se + dy[i];
			//printf("x%lld y%lld\n", nx, ny);

			if (nx == x && ny == y){
				printf("%f\n", ans(cnt));
				return 0;
			}
			q.push(mp(nx, ny));
		}

	}

	printf("0.0\n");
	return 0;

}#include <iostream>
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
//#define int long long
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for (int i=(n)-1;i>=0;i--)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define REPS(i,f,n) for (int i=(f)-1;i>=(n);i--)
//int dx[4] = {1, 0, 0, -1};
//int dy[4] = {0, 1, -1, 0};
 
ll n, d;
long double cnt = 0;
long double cnt_all = 0;
 
long double ans(void){
	double kakuritu = cnt / pow(4, n);
	return kakuritu;
}
 
int main(void){
 
	ll x, y;//目標
 
	cin >> n >> d;
	cin >> x >> y;
 
	ll dx[4] = {d, 0, 0, -d};
	ll dy[4] = {0, d, -d, 0};
 
	queue <pair<ll, ll> > q;
	q.push(mp(0, 0));
 
	//ll limit = pow(4, n - 1) + 1;
	ll j;
	while(!q.empty() && j <= 1000000){
		j++;
		//printf("j%lld\n", j);
 
		pair<ll, ll> tmp = q.front();//first x  second y
		q.pop();
 
		rep(i, 4){
			cnt_all++;
			ll nx = tmp.fi + dx[i];
			ll ny = tmp.se + dy[i];
			//printf("x%lld y%lld\n", nx, ny);
			q.push(mp(nx, ny));//queueに入れる
 
			if (pow(4, n - 1) < cnt_all && cnt_all <= pow(4, n) && nx == x && ny == y)
				printf("%Lf\n", cnt_all);
				cnt++;
		}	
	}
 
	if (cnt > 0)
		printf("%.10Lf\n", ans());
	else
		printf("0.0\n");
 
	return 0;
 
}