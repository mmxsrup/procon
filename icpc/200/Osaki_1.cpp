/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
#define MAX 86400
 
int main(){
  int n, t[MAX+1];
  while(cin >> n, n){
    memset(t, 0, sizeof(t));
    int H1, H2, M1, M2, S1, S2;
    for(int i = 0 ; i < n ; i++){
      scanf("%d:%d:%d %d:%d:%d", &H1, &M1, &S1, &H2, &M2, &S2);
      t[H1*3600+M1*60+S1]++, t[H2*3600+M2*60+S2]--;
    }
    int ans = 0;
     
    for(int i = 1 ; i <= MAX ; i++){
      t[i] += t[i-1];
      ans = max(ans, t[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
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

void slove(int n){
	vector<int> v(86410);
	rep(i, 86410) v[i] = 0;//初期化
	rep(i, n){
		string s, e;
		cin >> s >> e;
		//秒数に変換
		int start = 36000 * (s[0] - '0') + 3600 * (s[1] - '0') 
					+ 600 * (s[3] - '0') + 60 * (s[4] - '0')
					+ 10 * (s[6] - '0') + 1 * (s[7] - '0');
		int end = 36000 * (e[0] - '0') + 3600 * (e[1] - '0') 
					+ 600 * (e[3] - '0') + 60 * (e[4] - '0')
					+ 10 * (e[6] - '0') + 1 * (e[7] - '0');
		
		v[start]++;//この時電車が１台必要になったことを記録
		v[end]--;//この時電車が１台不要になったことを記録
	}
	int ans = 0;
	reps(i, 1, 86410){
		v[i] += v[i - 1];//ここが肝
		ans = max(ans, v[i]);
	}
	printf("%d\n", ans);
}
int main(void){
	rep(i, 1000000){
		int n; scanf("%d", &n);
		if(n == 0) break;
		slove(n);
	}
	return 0;
}