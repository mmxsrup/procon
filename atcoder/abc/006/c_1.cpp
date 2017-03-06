#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
 
	if(m<2*n||4*n<m)printf("-1 -1 -1\n");
	else {
		int a,b,c;
		c=(m-2*n)/2;
		b=(m-2*n)%2;
		a=n-b-c;
		printf("%d %d %d\n",a,b,c);
	}
 
}