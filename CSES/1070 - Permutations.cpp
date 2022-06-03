// Problem: Permutations
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1070
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
	if(n == 1){
		cout<<1;
		return;
	}
	if(n == 2 || n == 3){
		cout<<"NO SOLUTION";
		return;
	}
	cout<<2;
	for(int i = 4; i <= n; i++){
		if(i % 2 == 0)cout<<" "<<i;

	}
	
	// cout<<1;
	for(int i = 1; i <= n; i++){
		if(i % 2 == 1)cout<<" "<<i;

	}

	// vector<int> nums(n);
	// for(int i = 0; i <n; i++)nums[i] = i+1;
	// bool permutated = false;
	// while(next_permutation(nums.begin(),nums.end())){
		// bool cond = true;
		// for(int i = 0; i < n-1; i++){
			// if(abs(nums[i] - nums[i+1]) == 1){
				// cond = false;
				// break;
			// }
		// }
		// if(cond){
			// permutated = true;
			// break;
			// }
	// }
	// if(permutated){
		// cout<<nums[0];
		// for(int i=1; i < n; i++)cout<<" "<<nums[i];
	// }
	// else{
		// cout<<"NO SOLUTION";
	// }
	
	
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
    

    return 0;
}

