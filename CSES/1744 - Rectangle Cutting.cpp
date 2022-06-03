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
    int h,w; cin>>h>>w;
    vector<vector<int>> dp(h+1,vector<int>(w+1,1e9));
    for(int i = 1; i <= min(h,w); i++){
		dp[i][i] = 0;
	}
	for(int i = 1; i <= h; i++){
		for(int j = 1; j <= w; j++){
			for(int k = 1; k < i; k++){
				dp[i][j] = min(dp[i][j],dp[k][j] + dp[i-k][j]+1);
			}
			for(int k = 1; k < j; k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
			}
		}
	}
	cout<<dp[h][w];
}
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin>>t;
    while (t--) {
        solve();
    }
 
}

