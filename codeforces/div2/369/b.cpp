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

ll b[510][510];
int main(void){
	int n; cin >> n;
	int y, x;
	rep(i, n)rep(j, n){
		ll tmp; cin >> tmp;
		b[i][j] = tmp;
		if(tmp == 0){
			y = i; x = j;
		}
	}

	if(n == 1){
		printf("1\n");
		return 0;
	}

	vector<ll> tmp;
	rep(i, n){
		if(i == y) continue;
		ll t = 0;
		rep(j, n){
			t += b[i][j];
		}
		tmp.push_back(t);
	}
	rep(i, n){
		if(i == x) continue;
		ll t = 0;
		rep(j, n){
			t += b[j][i];
		}
		tmp.push_back(t);
	}

	if(x == n / 2 && y == n / 2 && n % 2 == 1){
		ll naname1 = 0, naname2 = 0;
		rep(i, n){
			naname1 += b[i][i];
		}
		rep(i, n){
			naname2 += b[i][n - i - 1];
		}
		tmp.push_back(naname1);
		tmp.push_back(naname2);
	}else if(x == y){
		ll naname1 = 0;
		rep(i, n){
			naname1 += b[i][i];
		}
		tmp.push_back(naname1);
	}else if(x + y == n - 1){
		ll naname2 = 0;
		rep(i, n){
			naname2 += b[i][n - i - 1];
		}
		tmp.push_back(naname2);
	}

	ll aim = 0;
	sort(all(tmp));
	if(tmp[0] == tmp[tmp.size() - 1]){
		aim = tmp[0];
	}else{
		// printf("kk\n");
		printf("-1\n");
		return 0;
	}


	if(x == n / 2 && y == n / 2 && n % 2 == 1){
		ll yoko = 0, tate = 0, naname1 = 0, naname2 = 0;
		rep(i, n){
			yoko += b[y][i];
		}
		rep(i, n){
			tate += b[i][x];
		}
		rep(i, n){
			naname1 += b[i][i];
		}
		rep(i, n){
			naname2 += b[i][n - i - 1];
		}
		if(yoko == tate && tate == naname1 && naname1 == naname2 && naname2 == yoko  && aim > tate){
			cout << aim - tate << endl;
			return 0;
		}else{
			printf("-1\n");
			return 0;
		}
	}else if(x == y){
		ll yoko = 0, tate = 0, naname1 = 0;
		rep(i, n){
			yoko += b[y][i];
		}
		rep(i, n){
			tate += b[i][x];
		}
		rep(i, n){
			naname1 += b[i][i];
		}

		if(yoko == tate && tate == naname1 && naname1 == yoko && aim > tate){
			cout << aim - tate << endl;
			return 0;
		}else{
			printf("-1\n");
			return 0;
		}
	}else if(x + y == n - 1){
		// printf("1\n");
		ll yoko = 0, tate = 0,naname2 = 0;
		rep(i, n){
			yoko += b[y][i];
		}
		rep(i, n){
			tate += b[i][x];
		}
		rep(i, n){
			naname2 += b[i][n - i - 1];
		}
		if(yoko == tate && tate == naname2 && naname2 == yoko && aim > tate){
			cout << aim - tate << endl;
			return 0;
		}else{
			printf("-1\n");
			return 0;
		}
	}else{
		ll yoko = 0, tate = 0;
		rep(i, n){
			yoko += b[y][i];
		}
		rep(i, n){
			tate += b[i][x];
		}

		if(yoko == tate && aim > tate){
			cout << aim - yoko << endl;
			return 0;
		}else{
			printf("-1\n");
			return 0;
		}
	}
	return 0;
}