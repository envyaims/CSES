// Author: envy <3 uwu
// Problem: Number Grid
// Attempted: 2022-03-12 11:56:21 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int MOD = 1e9 + 7;

void solve() {
    int r,c; cin>>r>>c;
    cout<<((r-1)^(c-1));
    
}
 
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}

