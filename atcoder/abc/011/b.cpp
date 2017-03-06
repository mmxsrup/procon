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
	string s;
	cin >> s;
	int size = s.size();

	printf("%c", toupper(s[0]));
	reps(i, 1, size)
		printf("%c", tolower(s[i]));

	printf("\n");
	return 0;
}


/*
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
 
int main()
{
  std::string S;
 
  std::cin >> S;
  printf("%c",toupper(S[0]));
  for(auto it : S.substr(1)){
    printf("%c",tolower(it));
  }
  putchar('\n');
  return 0;
}
*/