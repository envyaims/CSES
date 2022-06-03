// Author: envy <3 uwu
// Problem: Array Description
// Attempted: 2021-12-26 08:31:34 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
#define int long long
#define vt vector
#define pb push_back
#define ins insert
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define F first
#define S second
#define cont continue
#define SZ(x) (int)x.size()
#define pf printf
#define retf return false
#define rett return true

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORE(i,a,b) for (int i = (a); i <= (b); ++i)
#define ROF(i,a,b) for (int i = (a); i > (b); --i)
#define ROFE(i,a,b) for (int i = (a); i >= (b); --i)
#define trav(a,x) for (auto& a: x)
#define rv(x) trav(i,x)cin>>i;

template<class T> using maxpq = priority_queue<T>;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

const int MOD = 1e9+7;

void solve(){
	int n,m; cin>>n>>m;
	vt<vt<int>> dp(n,vt<int>(m+2));
	vt<int> a(n); 
	rv(a);
	if(a[0] == 0){
		FORE(i,1,m){
			dp[0][i] = 1;
		}
	}
	else dp[0][a[0]] = 1;
	FOR(i,1,n){
		if(a[i] == 0){
			FORE(j,1,m){
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
				dp[i][j] %= MOD;
			}
		}
		else{
			int j = a[i];
			dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i-1][j+1];
			dp[i][j] %= MOD;
		}
	}
	int ans = 0;
	trav(i,dp[n-1]){
		ans += i;
		ans %= MOD;
	}
	pf("%lld",ans);
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1; 
	//cin>>t;
	while(t--){
		solve();
	}
	
}
