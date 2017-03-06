#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
 
using namespace std;
 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
 
char buf[210];
	
int N;
bitset <210> input[210];
bitset <210> a[210];
bool used[210];
	
int main(void){
	int i,j;
	
	cin >> N;
	REP(i,N){
		scanf("%s", buf);
		REP(j,N) input[i][j] = (buf[j] == '1');
	}
	
	int rank = 0;
	REP(i,N){
		bitset <210> B = input[i];
		REP(j,N) if(B[j]){
			if(used[j]){
				B ^= a[j];
			} else {
				a[j] = B;
				used[j] = true;
				rank++;
				break;
			}
		}
	}
	
	cout << ((rank == N) ? "Odd" : "Even") << endl;
	
	return 0;
}