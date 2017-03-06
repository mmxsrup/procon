#include<stdio.h>
#include<stdlib.h>

unsigned long long const modnum=1000000007;

unsigned long long invdiv(unsigned long long p);

int main(void){
  unsigned long long M,S=0,n=0,ans=1;
  unsigned long long alls,rest,temp;
  unsigned long long i,j,k;
  char c;

  scanf("%llu%*c",&M);
  do{
    scanf("%llu%c",&temp,&c);
    S+=temp;
    n++;
  }while(c==' ');

  if(S+n-1>M) puts("NA");
  else if(S==0) puts("1");
  else{
    alls=M-S+1;
    rest=alls-n;

    for(i=1;i<=alls;i++){
      ans*=i;
      ans%=modnum;
    }
    for(i=1;i<=rest;i++){
      ans*=invdiv(i);
      ans%=modnum;
    }
    for(i=1;i<=n;i++){
      ans*=invdiv(i);
      ans%=modnum;
    }
    printf("%llu\n",ans);
  }
  return 0;
}


unsigned long long invdiv(unsigned long long p) {
    unsigned long long r[3], q;
    unsigned long long x[3];
    div_t clc;

    r[0] = p;
    r[1] = modnum;

    x[0] = 1;
    x[1] = 0;

    do {
        clc = div(r[0], r[1]);
        q = clc.quot;
        r[2] = clc.rem;
        while(x[0] < q * x[1]) x[0] += modnum;
        x[2] = (x[0] - q * x[1]) % modnum;

        r[0] = r[1];
        r[1] = r[2];

        x[0] = x[1];
        x[1] = x[2];
    } while(r[2] > 1);
    return x[2];
}