//この解法じゃ無理だ

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
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int main(void){
	queue<int> q;
	int n;
	cin >> n;
	q.push(n);

	int x, y, z;
	cin >> x >> y >> z;

	int cnt = 0;
	while(!q.empty() && cnt < 10000000){
		cnt++;
		//printf("%d\n", cnt);
		int tmp;
		tmp = q.front();
		q.pop();

		reps(i, 1, 4){
			int next = tmp - i;

			if (next != x && next != y && next != z && next >= 0) 
			{
				//printf("tmp:%d\n", tmp);
				//printf("next:%d\n", next);
				if (next == 0){
					printf("YES\n");
					return 0;
				}
				q.push(next);
			}
		}
	}
	printf("NO\n");
	return 0;
}