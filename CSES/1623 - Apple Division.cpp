// Author: envy
// Problem: Apple Division from CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1623
// Limits: 1000 ms, 512 MB
// Attempted: 2021-11-03 20:47:49 EST

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
	vector<int> nums(n);
	int total = 0;
	for(int& i: nums){
		cin>>i;
		total += i;
	}
	
	int mask = 1;
	for(int i = 0; i <= n; i++){
		mask *= 2;
	}
	
	int ans = 1e9;
	for(int i = mask; i >= mask/2; i--){
		int sum = 0;
		string s = bitset<21>(i).to_string();
		debug(s);
		reverse(s.begin(),s.end());
		for(int j = 0; j < n; j++){
			if(s[j] == '1'){
				sum += nums[j];
			}
			ans = min(ans,abs(sum - (total-sum)));
		}
	}
	cout<<ans;
	
	
}
