// Author: envy <3 uwu
// Problem: Range Update Queries
// Attempted: 2021-12-29 14:29:56 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
const int dx[8] = {1,-1,0,0,-1,-1,1,1}, dy[8] = {0,0,-1,1,1,-1,-1,1};
const int MOD = 1e9+7;

struct segtree{
	
	vector<int> seg;
	int _n;
	
	segtree(int nn){
		seg.resize(2*nn,0LL);
		_n = nn;
	}
	
	void update(int k, int x){
		k += _n;
		seg[k] += x;
		k /= 2;
		while(k > 0){
			seg[k] = seg[2*k] + seg[2*k+1];
			k /= 2;
		}
		
	}
	
	
	int query(int l, int r){
		l += _n, r += _n;
		int sum = 0;
		while(l <= r){
			if(l % 2 == 1){
				sum += seg[l];
				l++;
			}
			if(r % 2 == 0){
				sum += seg[r];
				r--;
			}
			l /= 2; r /= 2;
		}
	
		return sum;
	}
	
};

void solve(){
	int n,q; cin>>n>>q;
	vt<int> a(n+1);
	FORE(i,1,n){
		cin>>a[i];
	}
	segtree st(n+1);
	FORE(i,1,n){
		st.update(i,a[i]-a[i-1]);
	}
	while(q--){
		int t; cin>>t;
		if(t == 1){
			int a,b,k; cin>>a>>b>>k;
			st.update(a,k);
			st.update(++b,-k);
		}
		else{
			int k; cin>>k;
			pf("%lld\n",st.query(1,k));
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
