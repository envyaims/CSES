// author: envy uwu <3
// problem: Traffic Lights
// created: 1/26/2022 6:52 PM

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
    int x,n; cin>>x>>n;
    multiset<int> road;
    multiset<int> segs;
    road.insert(0);
    road.insert(x);
    segs.insert(x);
    for(int i = 0; i < n; i++){
        int v; cin>>v;
        auto up = road.upper_bound(v);
        auto down = prev(up,1);
        int orig = *up - *down;
        assert(segs.find(orig) != segs.end());
        segs.erase(segs.find(orig));
        segs.insert(*up-v);
        segs.insert(v-*down);
        road.insert(v);
        cout<<*(--segs.end())<<" ";

    }

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
