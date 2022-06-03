// Author: envy <3 uwu
// Problem: Dynamic Range Minimum Queries
// Attempted: 2021-12-29 12:48:49 EST

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

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
const int MOD = 1e9+7;

int n,q; 
struct segtree{
	
	vector<int> seg;
	
	void init(int size){
		seg.resize(2*n,0LL);
	}
	
	void update(int k, int x){
		k += n;
		seg[k] = x;
		k /= 2;
		while(k > 0){
			seg[k] = min(seg[2*k], seg[2*k+1]);
			k /= 2;
		}
		
	}
	
	
	int minquery(int l, int r){
		l += n, r += n;
		int minn = 1e9;
		while(l <= r){
			if(l % 2 == 1){
				ckmin(minn,seg[l]);
				l++;
			}
			if(r % 2 == 0){
				ckmin(minn,seg[r]);
				r--;
			}
			l /= 2; r /= 2;
		}
	
		return minn;
	}
	
};

void solve(){
	cin>>n>>q;
	segtree st;
	st.init(n);
	FOR(i,0,n){
		int a; cin>>a;
		st.update(i,a);
	}
	while(q--){
		int t; cin>>t;
		if(t == 1){
			int pos, x; cin>>pos>>x;
			st.update(--pos,x);
		}
		else{
			int l,r; cin>>l>>r;
			pf("%d\n",st.minquery(--l,--r));
		}
	}
	
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
