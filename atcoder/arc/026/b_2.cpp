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

 
int main()
{
  ll n,sum=0;
  scanf("%lld", &n); 
  for(ll i=1;i*i<=n;i++)
  {
    if(n%i==0)
    {
      sum+=i+(n/i);
      if(i==n/i)sum-=i;
    }
  } 
  sum-=n;

  if (n == sum) //i==1の時のペアで自分も足してしまっているので、２倍にして比べてもいい
  {
    printf("Perfect\n");
  }else if(n < sum){
    printf("Abudant\n");
  }else{
    printf("Deficient\n");
  }
  
  return 0;
  
}
