#ifndef LOCAL
#include <bits/stdc++.h>
#define debug(...) 0
#else
#include "/Users/envyaims/Documents/template/stdc++.h"
#include "/Users/envyaims/Documents/template/debug.cpp"
#endif

using namespace std;
#define F first
#define S second
#define all(x) x.begin(), x.end()
using ll = long long;
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

ll cross(ll a, ll b, ll c, ll d){
	return a * d - c * b;
}

void solve(){
	// p2 - p1
	// p3 - p1
	// 
	ll a,b,c,d,e,f; cin >> a >> b >> c >> d >> e >> f;
	c -= a;
	d -= b;
	e -= a;
	f -= b;
	ll cr = cross(c, d, e, f);
	if(cr > 0)puts("LEFT");
	else if(cr == 0)puts("TOUCH");
	else puts("RIGHT");
	
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}


