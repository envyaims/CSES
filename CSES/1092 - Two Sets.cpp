// Author: envy
// Problem: Two Sets from CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1092
// Limits: 1000 ms, 512 MB
// Attempted: 2021-11-02 07:52:46 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	if(n % 4 == 0){
		cout<<"YES"<<endl;
		cout<<n/2<<endl;
		for(int i = 1; i <= n/4; i++){
			cout<<i<<" "<<n-i+1<<" ";
		}
		cout<<endl;
		cout<<n/2<<endl;
		for(int i = n/4+1; i <= n/2; i++){
			cout<<i<<" "<<n-i+1<<" ";
		}
		
	}
	else if(n % 4 == 3){
		cout<<"YES"<<endl;
		int sum = (n*(n+1))/4;
		vector<bool> taken(n+1);
		int sumnow = 0;
		int cnt = 0;
		for(int i = n; i >= 1; i--){
			if(sum-sumnow < i){
				cnt++;
				taken[sum-sumnow] = true;
				break;
			}
			else{
				cnt++;
				sumnow += i;
				taken[i] = true;
				if(sumnow == sum){
					cout<<endl;
					break;
				}
			}
		}
		cout<<cnt<<endl;
		for(int i = 1; i <= n; i++){
			if(taken[i]){
				cout<<i<<" ";
			}
		}
		cout<<endl;
		cout<<n-cnt<<endl;
		for(int i = 1; i <= n; i++){
			if(!taken[i]){
				cout<<i<<" ";
			}
		}
		
	}
	else cout<<"NO";
	
}
