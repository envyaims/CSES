#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define int long long

struct segtree{
	vector<int> seg;
	int N;
	segtree(int M){
		N = M;
		seg.resize(2*N);
	}
	void update(int k, int x){
		k += N; 
		seg[k] = x;
		while(k /= 2){
			seg[k] = seg[2*k]+seg[2*k+1];
		}
	}
	int query(int l, int r){
		l += N; r += N;
		int ret = 0;
		while(l <= r){
			if(l&1){
				ret += seg[l];
				++l;
			}
			if(!(r&1)){
				ret += seg[r];
				--r;
			}
			l /= 2; r /= 2;
		}
		return ret;
	}
};

void solve(){
	int n,q; cin>>n>>q;
	segtree st(n);
	for(int i = 0; i < n; i++){
		int x; cin>>x;
		st.update(i,x);
	}
	while(q--){
		int t, a, b; cin>>t>>a>>b;
		if(t == 1){
			st.update(a-1,b);
		}
		else cout<<st.query(a-1,b-1)<<"\n";
	}
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}


