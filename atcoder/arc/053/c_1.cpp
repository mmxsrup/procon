//#include <bits/stdc++.h>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector> 
#include <functional>
#include <iostream>


using namespace std;
typedef long long ll;
/*
int main(){
	int n;	cin>>n;
	vector<pair<ll,ll> > m,k,p;
	for(int i=0;i<n;i++){
		ll a,b;	cin>>a>>b;
		if(a<b)	m.push_back(make_pair(a,b));
		else if(a==b)	k.push_back(make_pair(a,b));
		else 	p.push_back(make_pair(b,a));
	}
	sort(m.begin(),m.end());
	sort(p.begin(),p.end());	reverse(p.begin(),p.end());
	ll cur=0,ans=0;
	for(auto it:m){
		ans=max(ans,cur+it.first);
		cur+=it.first-it.second;
	}
	for(auto it:k)	ans=max(ans,cur+it.first);
	for(auto it:p){
		ans=max(ans,cur+it.second);
		cur+=it.second-it.first;
	}
	cout<<ans<<endl;
	return 0;
}
*/

int main() {
	long long int N;
	cin >> N;
 
	vector<pair<long long int, long long int> >up, down;
	long long int last = 0;
	for( size_t i = 0; i < N; i++ ) {
		long long int A, B;
		cin >> A >> B;
		last += A - B;
		if( A > B ) {
			up.emplace_back( make_pair( B, A ) );
		} else {
			down.emplace_back( make_pair( A, B ) );
		}
	}
	sort( down.begin(), down.end() );
	long long int ans = 0, now = 0;
	for( size_t i = 0; i < down.size(); i++ ) {
		ans = max( ans, now + down[i].first );
		now += down[i].first - down[i].second;
	}
	sort( up.begin(), up.end() );
	reverse( up.begin(), up.end() );
	for( size_t i = 0; i < up.size(); i++ ) {
		ans = max( ans, now + up[i].second );
		now += up[i].second - up[i].first;
	}
	cout << ans << endl;
	printf("\n");
	printf("%d\n", down.size());