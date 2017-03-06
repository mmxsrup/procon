/*
026
オーダーを√Nにするために
AがNの約数の時　N/AもNの約数
AかN/Aがわかればもう片方もすぐにわかる

両サイドからはさみ込むイメージ

*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector> 
#include <functional>
#include <bitset>
#include <queue>
#include <cmath>
using namespace std;

typedef long long ll;

int main(void){
	ll N;
	ll sum = 0;

	scanf("%lld", &N);

	for (ll i = 1; i * i <= N; ++i)
	{
		if (N % i == 0)
		{
			sum += i + (N / i); //一度に２つの約数がわかる
			if (i == N / i)
			{
				sum -= i;
			}
		}
	}

	sum -= N;

	if (N == sum) //i==1の時のペアで自分も足してしまっているので、２倍にして比べてもいい
	{
		printf("Perfect\n");
	}else if(N < sum){
		printf("Abundant\n");
	}else{
		printf("Deficient\n");
	}
	
	return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main()
{
	ll n,sum=0;
	cin>>n;	
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			sum+=i+(n/i);
			if(i==n/i)sum-=i;
		}
	}	
	sum-=n;
	if(sum>n)cout<<"Abundant"<<endl;
    else if(sum==n)cout<<"Perfect"<<endl;
    else cout<<"Deficient"<<endl;
    return 0;
}
*/
