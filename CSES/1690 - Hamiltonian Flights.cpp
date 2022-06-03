// Author: envy <3 uwu
// Problem: Hamiltonian Flights
// Attempted: 2021-12-26 12:23:02 EST

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
	int n,m;cin>>n>>m;
	vt<vt<int>> graph(n);
	FOR(i,0,m){
		int a,b; cin>>a>>b;
		graph[--b].pb(--a);
	}
	vt<vt<int>> dp(1<<n,vt<int>(n));
	
	auto in = [&](int s, int a){
		return (s&(1<<a));
	};
	
	dp[1][0] = 1;
	FOR(s,2,1<<n){
		// first city is not in
		if(!in(s,0))continue;
		
		// last city is in but it is not the final subset
		if(in(s,n-1) && s != (1<<n)-1)continue;
		
		FOR(i,0,n){
			if(in(s,i)){
				int non = s - (1<<i);
				trav(j,graph[i]){
					dp[s][i] += dp[non][j];
					dp[s][i] %= MOD;
				}
			}
		}
	}
	pf("%lld",dp[(1<<n)-1][n-1]);
	
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
