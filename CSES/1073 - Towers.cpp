// author: envy uwu <3
// problem: Towers
// created: 1/26/2022 6:39 PM

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

template<class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template<class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

void solve() {
    int n; cin>>n;
    multiset<int> towers;
    for(int i = 0; i < n; i++){
        int v; cin>>v;
        auto it = towers.upper_bound(v);
        if(it == towers.end()){
            towers.insert(v);
        }
        else{
            towers.erase(it);
            towers.insert(v);
        }
    }
    cout<<towers.size();
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
