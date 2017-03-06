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


int main(void){
	while(1){
		string s1;
		cin >> s1;
		if(s1 == "#")break;
		string s2;
		cin >> s2;
		int size1 = s1.size();
		int size2 = s2.size();
		int minsize = min(size1, size2);

		rep(i, minsize){
			if(s1[i] - 'a' < s2[i] - 'a'){
				printf("Yes\n");
				//printf("1\n");
				break;
			}else if(s1[i] - 'a' > s2[i] - 'a'){
				//printf("%d\n", i);
				printf("No\n");
				//printf("2\n");
				break;
			}

			if(i == minsize - 1){
				if (minsize == size1)
					printf("Yes\n");
				else
					printf("No\n");
			}
		}

	}
	return 0;
}