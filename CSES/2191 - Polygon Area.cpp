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

struct point{
	ll x, y;
};

void solve(){
	int n; cin >> n;
	// shoelace theorem
	vector<point> pts(n);
	for(int i = 0; i < n; i++){
		cin >> pts[i].x >> pts[i].y;
	}
	
	ll left = 0;
	for(int i = 0; i < n; i++){
		left += pts[i].x * pts[(i + 1)%n].y;
	}
	ll right = 0;
	for(int i = 0; i < n; i++){
		right += pts[i].y * pts[(i+1)%n].x;
	}
	debug(left,right);
	cout << abs(right - left);
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin>>t;
	while(t--){
		solve();
	}
}


