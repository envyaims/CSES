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
    int r, c; cin>>r>>c;
    if(r % 2 == 0 && c <= r){
		cout<<r * r - c+1;
	}
	else if(c % 2 == 1 && r <= c){
		cout<<c * c - r+1;
	}
	else if(c % 2 == 0 && r <= c){
		cout<<(c-1) * (c-1) + r;
	}
	else if(r % 2 == 1 && c <= r){
		cout<<(r-1) * (r-1) + c;
	}
	cout<<"\n";
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin>>t;
    while (t--) {
        solve();
    }
 
}

