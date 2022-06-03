// Author: envy <3 uwu
// Problem: Elevator Rides
// Attempted: 2021-12-26 11:48:14 EST

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
	vt<int> w(n); 
	rv(w);
	vt<pair<int,int>> dp(1<<n,{1e9,1e9});
	dp[0] = {1,0};
	FOR(i,1,1<<n){
		FOR(j,0,n){
			if(i&(1<<j)){
				pair<int,int> cur = dp[i^(1<<j)];
				cur.second += w[j];
				if(cur.second > m){
					cur = {cur.first+1,w[j]};
				}
				ckmin(dp[i],cur);
			}
		}
	}
	pf("%lld",dp[(1<<n)-1].first);
	
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
