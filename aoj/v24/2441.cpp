#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
 
int main(void){
    long long s;
    cin >> s;
    long long add = 0;
    double i;
    for (i = 0; i < 1000; ++i){
        double l = pow(10.0, i) - 1;//????????????+1
        double r = pow(10.0, i + 1) - 1;//?????????
        // printf("i %d  l %f  r %f\n", i, l, r);
        long long l3 = l / 3.0, l5 = l / 5.0, l15 = l / 15.0;
        long long r3 = r / 3.0, r5 = r / 5.0, r15 = r / 15.0;
        // printf("r3 %d r5 %d  r15 %d \n", r3, r5, r15);
 
        long long fizz = r3 - l3;//????????????3????????°????????°
        long long buzz = r5 - l5;//????????????5????????°????????°  
        long long fizzbuzz = r15 - l15;//????????????15????????°????????°
        long long num = r - l + 1;//??????????????°??????????¨???°
        //printf("%d %d %d %d\n", fizz, buzz, fizzbuzz, num);
        //????????????????????°
        long long sumketa = i * (num - fizz - buzz - fizzbuzz) + 4 * (fizz + buzz) + 8 * (fizzbuzz);
        add += sumketa;
        // printf("%d %d\n", sumketa, add);
        if(add > s){
            // printf("nukeru %d %d\n", add, sumketa);
            add -= sumketa;
            break;
        }
    }
 
    //pow(10, i - 1)?????§?????°????????????????¨????add?????\??£?????????
    long long now = pow(10.0, i - 1);
    int keta = i;
    printf("add %lld now %lld keta %d\n", add, now, keta);
     
    string mozi;

    while(mozi.size() > s - add + 100){
        printf("%lu %lld \n", mozi.size(), add);
        now++;
        if(now % 3 == 0 && now % 5 == 0){
            mozi += "FizzBuzz";
            add += 8;
        }
        else if(now % 3 == 0 && now % 5 != 0){
            mozi += "Fizz";
            add += 4;
        }
        else if(now % 3 != 0 && now % 5 == 0){
            mozi += "Buzz";
            add += 4;
        }
        else{
            mozi += to_string(now);
            add += keta;
        }
    }
 
    rep(i, mozi.size()){
        printf("%c", mozi[i]);
    }
    printf("\n");
    reps(j, s - add, 20){
        printf("%c", mozi[j]);
    }
    printf("\n");
    return 0;
}