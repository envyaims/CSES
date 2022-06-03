// Author: envy
// Problem: Coin Piles from CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1754
// Limits: 1000 ms, 512 MB
// Attempted: 2021-11-01 20:16:36 EST

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
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		if(max(a,b) > 2 * min(a,b)){
			cout<<"NO"<<endl;
			continue;
		}
		if((a+b) % 3 == 0){
			cout<<"YES"<<endl;;
		}
		else{
			if(a % 3 == 2 and b % 3 == 1){
				cout<<"YES"<<endl;
			}
			else if(b % 3 == 2 and a % 3 == 1){
				cout<<"YES"<<endl;
			}
			else cout<<"NO"<<endl;
			
		}
	}
	
}
