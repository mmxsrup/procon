#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
int n,d,m,sum[101];
vector<int> missile[100];
int main() {
    for(;cin>>n>>d;){
        if(n==0)break;
        fill(sum,sum+n+1,0);
        for(int i=0;i<n;i++){
            cin>>m;
            missile[i]=vector<int>(m);
            for(int j=0;j<m;j++)cin>>missile[i][j];
            sum[i]=accumulate(missile[i].begin(),missile[i].end(),0);
        }
        bool ok=true;
        while(1){
            int M=max_element(sum,sum+n)-sum;
            int MV=sum[M];
            if(MV==0)break;
            int cnt=0;
            for(int i=0;i<n;i++){
                while(!missile[i].empty()){
                    sum[i]-=missile[i].back();
                    if(abs(sum[max_element(sum,sum+n)-sum]-sum[i])>d){
                        sum[i]+=missile[i].back();
                        break;
                    }
                    missile[i].pop_back();
                    cnt++;
                }
            }
            if(cnt==0){
                ok=false;
                break;
            }
        }
        cout<<(ok?"Yes":"No")<<endl;
    }
}  