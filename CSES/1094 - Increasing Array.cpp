// Problem: Increasing Array
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1094/
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(){
	int n;
	cin>>n;
	int nums[n];
	long long output = 0;
	for(int i = 0; i < n; i++)cin>>nums[i];
	for(int i = 1; i < n; i++){
		int dif = nums[i-1] - nums[i];
		if(dif > 0){
			output+= dif;
			nums[i] += dif;
			}
	}
	cout<<output;
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}

