// author: envy uwu <3
// problem: Acyclic Graph Edges
// created: 3/13/2022 1:05 PM

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

void solve() {
    int n,m; cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u,v; cin>>u>>v;
        cout<<min(u,v)<<" "<<max(u,v)<<endl;
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
