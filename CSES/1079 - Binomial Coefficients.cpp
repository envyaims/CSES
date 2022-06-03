// Author: envy <3 uwu
// Problem: Binomial Coefficients
// Attempted: 2022-05-27 22:15:04 EST

#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 0
#else
#include "C:\programmingfunnyxd\debug.cpp"
#endif
using namespace std;
using ll = long long;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())
const int MOD = 1e9 + 7;
template<int D, typename T>struct vt : public vector<vt<D - 1, T>> { template<typename... Args>
	vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}};
template<typename T> struct vt<1, T> : public vector<T> {
	vt(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
template<class T> using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool ckmin(T& a, const T& b){return b<a?a=b,1:0;}
template<class T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

#define int long long

int pow(int a,int b,int m){int ans=1;while(b){if(b&1){ans=(ans*a)%m;}b>>=1;a=(a*a)%m;}return ans;}
vector<int> facts = {1,1};
vector<int> inverse;
int ncr(int n, int k){
   return facts[n] * inverse[k] % MOD * inverse[n - k] % MOD;
}

void solve() {
	int a,b;
	cin >> a >> b;
	cout << ncr(a,b) << "\n";
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	
	
	int m = 1e6;
	inverse.resize(m+1);
	inverse[0] = 1;
    inverse[1] = 1;
    for(int i = 2; i <= m; i++){
        facts.push_back(facts.back() * i % MOD);
        inverse[i] = pow(facts.back(),MOD-2,MOD);
    }
	cin >> t;
	for(int test = 1; test <= t; test++){
		solve();
	}
}
